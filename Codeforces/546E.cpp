#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define yes() cout<<"Yes\n"
#define no() cout<<"No\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
#define MX 207
using namespace std;

int mp[MX][MX];

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
        mp[v][u]= m;
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

std::vector<int> adj[MX];

int main()
{
	memset( mp, -1, sizeof(mp) );
	fast;
	int n,m;
	cin>>n>>m;

	int arr[n+5], brr[n+5];
	Dinic Din( 2*n+5, 2*n+1, 2*n+2 );
	int tot= 0, tot2= 0;


	for( int i=1;i<=n;i++ )
	{
		cin>>arr[i];
		tot+= arr[i];

		Din.add_edge( 2*n+1, i, arr[i] );
		Din.add_edge( i, i+n, Din.flow_inf );
	}

	for( int i=1;i<=n;i++ )
	{
		cin>>brr[i];
		tot2+= brr[i];

		Din.add_edge( i+n, 2*n+2, brr[i] );
	}
	

	for( int i=0;i<m;i++ )
	{
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);

		Din.add_edge( u, v+n, Din.flow_inf );
		Din.add_edge( v, u+n, Din.flow_inf );
	}

	int ans= Din.flow();	

	if(tot!=ans or tot!=tot2)
		return cout<<"NO\n", 0;

	cout<<"YES\n";

	for( int i=1;i<=n;i++ )
	{
		for( int j=1;j<=n;j++ )
		{
			if( mp[i][j+n]>=0 )
				cout<<Din.edges[mp[i][j+n]].flow<<" ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}

}
