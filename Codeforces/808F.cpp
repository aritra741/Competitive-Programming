#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define f first
#define s second
#define mx 100007
using namespace std;

bool ok[2 * mx];

struct FlowEdge
{
	int v, u;
	long long cap, flow = 0;
	FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic
{
	const long long flow_inf = 1e18;
	vector<FlowEdge> edges;
	vector<vector<int>> adj, usedInFlow;
	int n, m = 0;
	int s, t;
	vector<int> level, ptr;
	queue<int> q;

	Dinic(int n, int s, int t) : n(n), s(s), t(t)
	{
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
		usedInFlow.resize(n);
	}

	void add_edge(int v, int u, long long cap)
	{
		edges.emplace_back(v, u, cap);
		edges.emplace_back(u, v, 0);
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	bool bfs()
	{
		while (!q.empty())
		{
			int v = q.front();
			q.pop();
			for (int id : adj[v])
			{
				if (edges[id].cap - edges[id].flow < 1)
					continue;
				if (level[edges[id].u] != -1)
					continue;
				level[edges[id].u] = level[v] + 1;
				q.push(edges[id].u);
			}
		}
		return level[t] != -1;
	}

	long long dfs(int v, long long pushed)
	{
		if (pushed == 0)
			return 0;
		if (v == t)
			return pushed;
		for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++)
		{
			int id = adj[v][cid];
			int u = edges[id].u;
			if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
				continue;
			long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
			if (tr == 0)
				continue;
			edges[id].flow += tr;
			edges[id ^ 1].flow -= tr;
			return tr;
		}
		return 0;
	}

	long long flow()
	{
		long long f = 0;
		while (true)
		{
			fill(level.begin(), level.end(), -1);
			level[s] = 0;
			q.push(s);
			if (!bfs())
				break;
			fill(ptr.begin(), ptr.end(), 0);
			while (long long pushed = dfs(s, flow_inf))
			{
				f += pushed;
			}
		}
		return f;
	}
};

void sieve()
{
	ok[0] = ok[1] = 1;

	for ( int i = 2; i < mx; i++ )
	{
		if (ok[i])
			continue;

		for ( int j = i * 2; j < mx; j += i )
			ok[j] = 1;
	}
}

int p[107], c[107], l[107];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();

	int n, k;
	cin >> n >> k;

	int cnt= 0;

	for ( int i = 0; i < n; i++ )
		cin >> p[i] >> c[i] >> l[i], cnt+= p[i];

	int left = 1, r = n, ans = -1;

	while (left < r - 5)
	{
		int mid = (left + r) / 2;

		Dinic Din(2 * n + 7, 2 * n + 1, 2 * n + 2);

		int tot= 0, max_power_of_1= 0, lvl;
		std::vector<int> pp, cc, lp;

		for( int i=0;i<n;i++ )
		{
			if(l[i]>mid)
				continue;
			if(c[i]==1)
			{
				if(p[i]> max_power_of_1)
					max_power_of_1= p[i], lvl= l[i];
			}
			else
				tot+= p[i], pp.push_back(p[i]), cc.push_back(c[i]), lp.push_back(l[i]);
		}

		if(max_power_of_1)
			pp.push_back(max_power_of_1), cc.push_back(1), lp.push_back(lvl), tot+= max_power_of_1;

		for ( int i = 0; i < pp.size(); i++ )
		{
			if (lp[i] > mid)
				continue;
			if(cc[i]&1)
			{
				Din.add_edge( 2*n+1, i+1, pp[i] );
				if (cc[i] & 1)
					for ( int j = 0; j < pp.size(); j++ )
						if ( cc[j]%2==0 and lp[j]<=mid and !ok[cc[i] + cc[j]] )
							Din.add_edge( i + 1, j + 1, Din.flow_inf );
			}
			else
				Din.add_edge( i+1, 2*n+2, pp[i] );
		}

		int min_cut = Din.flow();

		if ( tot - min_cut >= k )
			ans = mid, r = mid;
		else
			left = mid;
	}

	// cout<<left<<" "<<r<<endl;

	while (left <= r)
	{
		Dinic Din(2 * n + 7, 2 * n + 1, 2 * n + 2);

		int max_power_of_1 = 0, lvl;
		int tot = 0;

		std::vector<int> pp, cc, lp;

		for( int i=0;i<n;i++ )
		{
			if(l[i]>left)
				continue;
			if(c[i]==1)
			{
				if(p[i]> max_power_of_1)
					max_power_of_1= p[i], lvl= l[i];
			}
			else
				tot+= p[i], pp.push_back(p[i]), cc.push_back(c[i]), lp.push_back(l[i]);
		}

		if(max_power_of_1)
			pp.push_back(max_power_of_1), cc.push_back(1), lp.push_back(lvl), tot+= max_power_of_1;

		for ( int i = 0; i < pp.size(); i++ )
		{
			if (lp[i] > left)
				continue;
			if(cc[i]&1)
			{
				Din.add_edge( 2*n+1, i+1, pp[i] );
				if (cc[i] & 1)
					for ( int j = 0; j < pp.size(); j++ )
						if ( cc[j]%2==0 and lp[j]<=left and !ok[cc[i] + cc[j]] )
							Din.add_edge( i + 1, j + 1, Din.flow_inf );
			}
			else
				Din.add_edge( i+1, 2*n+2, pp[i] );
		}

		int min_cut = Din.flow();

		if ( tot - min_cut >= k and (left<ans or ans==-1) )
			ans = left;

		left++;
	}

	cout << ans << "\n";
}
