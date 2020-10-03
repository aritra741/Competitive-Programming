#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define f first
#define s second
using namespace std;

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

int n,m;
int d1[]= {1,0,-1,0};
int d2[]= {0,1,0,-1};

int getVal( int x, int y )
{
	return m*(x-1)+y;
}


int main()
{
	int tc;
	scanf("%d", &tc);

	for( int t=1;t<=tc;t++ )
	{
		scanf("%d%d", &n, &m);

		char s[n+5][m+5];

		int cnt= 0;

		getchar();

		for( int i=1;i<=n;i++ )
		{
			scanf("%s", s[i]+1);

			for( int j=1;j<=m;j++ )
				if(s[i][j]=='*')
					cnt++;
		}

		Dinic Din( 2*n*m+5, 2*n*m+1, 2*n*m+2 );

		for( int i=1;i<=n;i++ )
		{
			for( int j=1;j<=m;j++ )
			{
				// cout<<i<<" "<<j<<" "<<getVal(i,j)<<endl;
				if(  j==1 or i==1 or j==m or i==n )
					Din.add_edge( getVal(i,j)+n*m, 2*n*m+2, 1 );

				Din.add_edge( getVal(i,j), getVal(i,j)+n*m, 1 );

				if( s[i][j]=='*' )
					Din.add_edge( 2*n*m+1, getVal(i,j), 1 );

				for( int k=0;k<4;k++ )
				{
					int x= i+d1[k];
					int y= j+d2[k];

					if( x>=1 and x<=n and y>=1 and y<=m )
						Din.add_edge( getVal(i,j)+n*m, getVal(x,y), 1 );
				}
			}
		}

		printf("Case %d: ", t);

		if( cnt==Din.flow() )
			printf("yes\n");
		else
			printf("no\n");
	}
}
