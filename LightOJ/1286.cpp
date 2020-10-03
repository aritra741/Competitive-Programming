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
        int m,n;
        scanf("%d%d", &m, &n);
 
        Dinic Din( m+n+7, m+n+1, m+n+2 );
 
        int tot= 0, p[m+5];
 
        for( int i=1;i<=m;i++ )
        {
            scanf("%d", &p[i]);
            tot+= p[i];
            Din.add_edge( m+n+1, i, p[i] );
        }
 
        int c[n+5];
 
        for( int i=1;i<=n;i++ )
        {
            scanf("%d", &c[i]);
            Din.add_edge( i+m, m+n+2, c[i] );
        }
 
        for( int i=1;i<=m;i++ )
        {
            int q;
            scanf("%d", &q);
 
            for( int j=1;j<=q;j++ )
            {
                int pp;
                scanf("%d", &pp);
 
                Din.add_edge( i, pp+m, Din.flow_inf );
            }
        }
 
        int ans= max( 0LL, tot-Din.flow() );
 
        printf("Case %d: %d\n", t, ans);
    }
}
 
