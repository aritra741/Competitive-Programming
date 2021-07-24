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
#define ld long double
#define MX 57
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

std::vector<int> adj[MX];
std::vector<ll> wt[MX];


int main()
{
	fast;

    int n,m,x;
    cin>>n>>m>>x;

    for( int i=0;i<m;i++ )
    {
        int u,v;
        ll c;
        cin>>u>>v>>c;

        adj[u].push_back(v);
        // adj[v].push_back(u);
        wt[u].push_back(c);
        // wt[v].push_back(c);
    }

    double l= 0, r= 1e14;
    ld ans= 0;

    for( int i=0;i<=700;i++ )
    {
        double mid= (l+r)/2;

        Dinic Din( n+5, n+1, n+2 );
        Din.add_edge( n+1, 1, x );

        for( int j=1;j<=n;j++ )
        {
            for( int k=0;k<adj[j].size();k++ )
            {
                int v= adj[j][k];
                ll c= wt[j][k];

                Din.add_edge( j, v, c/mid );
            }
        }

        Din.add_edge( n, n+2, Din.flow_inf );
        int vl= Din.flow();

        if( vl>=x )
        {
            l= mid, ans= mid;
        }
        else
            r= mid;
    }

    cout<<setprecision(10)<<fixed<<ans*x<<endl;
}
