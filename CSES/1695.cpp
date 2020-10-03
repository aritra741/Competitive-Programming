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

int idx[507];

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    Dinic Din( n+7, 1, n );

    for( int i=0;i<m;i++ )
    {
        int u,v;
        scanf("%d %d", &u, &v);

        Din.add_edge(u,v,1);
        Din.add_edge(v,u,1);
    }

    ll fl= Din.flow();

    printf("%lld\n", fl);

    queue<int>q;
    q.push(1);

    std::vector<bool> vis(n+1,0);
    vis[1]= 1;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for( auto x: Din.adj[u] )
        {
            if( !vis[Din.edges[x].u] and Din.edges[x].cap>Din.edges[x].flow )
            {
                vis[Din.edges[x].u]= 1;
                q.push(Din.edges[x].u);
            }
        }
    }

    for( int i=0;i<Din.m;i+= 4 )
        if( vis[Din.edges[i].u] xor vis[Din.edges[i].v] )
            printf("%d %d\n", Din.edges[i].u, Din.edges[i].v);

}
