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
		int n;
        double d;
        scanf("%d %lf", &n, &d);

        int x[n+5], y[n+5], m[n+5], cnt[n+5];

        int tot= 0;

        for( int i=1;i<=n;i++ )
        {
            scanf("%d %d %d %d", &x[i], &y[i], &cnt[i], &m[i]);
            tot+= cnt[i];
        }

        std::vector<int> v;

        for( int i=1;i<=n;i++ )
        {
            Dinic Din( 2*n+5, 2*n+1, i );
            for( int j=1;j<=n;j++ )
            {
                Din.add_edge( 2*n+1, j, cnt[j] );
                Din.add_edge( j, j+n, m[j] );
                for( int k=1;k<=n;k++ )
                {
                    if(j==k)
                        continue;

                    if( ( x[j]-x[k] )*( x[j]-x[k] )+( y[j]-y[k] )*( y[j]-y[k] )+1e-9<=d*d )
                        Din.add_edge( j+n, k, Din.flow_inf );
                }
            }

            if( Din.flow()==tot )
                v.push_back(i-1);
        }

		printf("Case %d: ", t);

        for( int i=0;i<(int)v.size()-1;i++ )
            printf("%d ", v[i]);

        if( v.size() )
            printf("%d\n", v.back());
        else
            printf("-1\n");
	}
}
