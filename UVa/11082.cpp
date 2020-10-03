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

int main()
{
	int tc;
	scanf("%d", &tc);

	for( int t=1;t<=tc;t++ )
	{
		int n,m;
		scanf("%d %d", &n, &m);

		int r[n+7], c[m+7];
		int x= 0, y= 0;

		for( int i=1;i<=n;i++ )
			scanf("%d", &r[i]), y= r[i], r[i]-= x, x= y;
		x= 0, y= 0;
		for( int i=1;i<=m;i++ )
			scanf("%d", &c[i]), y= c[i], c[i]-= x, x= y;
		
		Dinic Din( n+m+7, n+m+1, m+n+2 );

		for( int i=1;i<=n;i++ )
		{
			Din.add_edge( n+m+1, i, r[i]-m );

			for( int j=1;j<=m;j++ )
				Din.add_edge( i, j+n, 19 );
		}

		for( int i=1;i<=m;i++ )
			Din.add_edge( i+n, n+m+2, c[i]-n );

		printf("Matrix %d\n", t);

		int ff= Din.flow();

		int ans[n+5][m+5];

		for( int i=1;i<=n;i++ )
			for( auto e: Din.adj[i] )
				if( Din.edges[e].v==i and Din.edges[e].flow>=0 )
					ans[i][Din.edges[e].u-n]= Din.edges[e].flow+1;

		for( int i=1;i<=n;i++ )
			for( int j=1;j<=m;j++ )
				printf("%d%c", ans[i][j], (j==m)?'\n':' ');

		if(t<tc)
			printf("\n");
	}
}
