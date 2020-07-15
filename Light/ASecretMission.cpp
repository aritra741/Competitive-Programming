#include <bits/stdc++.h>
#define mx 50007
#define pii pair<int,int>
#define piii pair<int,pii>
#define f first
#define s second
using namespace std;

int lvl[mx], par[mx][20], Max[mx][20], parent[mx], k=1, dist[mx];
bool vis[mx];
vector<piii> graph;
vector<int> adj[mx], cost[mx];

int find_par( int u )
{
    if( parent[u]!=u )
        return find_par( parent[u] );
    return u;
}

void dfs( int u, int cnt, int p )
{
    vis[u]= 1;
    lvl[u]= cnt;
    par[u][0]= p;

    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];

        if( vis[v] )
            continue;
        Max[v][0]= cost[u][i];
        dist[v]= cost[u][i];
        dfs( v, cnt+1, u );
    }
}

void init( int n )
{
    for( int i=0;i<=n;i++ )
        parent[i]= i;
}

void table( int n )
{
    for( int j=1;(1<<j)<=n;j++ )
        for( int i=1;i<=n;i++ )
            if( par[i][j-1]!=-1 )
            par[i][j]= par[par[i][j-1]][j-1],
            Max[i][j]= max( Max[i][j-1], Max[par[i][j-1]][j-1]);

}

int query( int n, int p, int q )
{
    if( lvl[p]<lvl[q] )
        swap( p,q );

    if(p==q)
        return 0;
    int log= 1;
    int ret= 0;

    while(1)
    {
        int next= log+1;

        if( (1<<next)>lvl[p] )
            break;
        log++;
    }

    ret= dist[p];
    for( int i=log;i>=0;i-- )
    {
        if( lvl[p]-(1<<i)>=lvl[q] )
            p= par[p][i],
            ret= max( ret, Max[p][i] );
    }

    if(p==q)
        return ret;

    for( int j=log; j>=0;j-- )
    {
        if( par[p][j]!=-1 and par[p][j]!=par[q][j] )
            p= par[p][j], q= par[q][j], ret= max( ret, Max[p][j] ), ret=max( ret, Max[q][j] );
    }
    cout<<"ei 4\n";
    return max(ret, max(dist[p], dist[q]));
}

int main()
{
    int tc;
    cin>>tc;

    for( int t=1;t<=tc;t++ )
    {
        int n,m;
        scanf("%d %d", &n, &m);

        while(m--)
        {
            int p,q,w;
            scanf("%d %d %d", &p, &q, &w);

            graph.push_back( piii(w, pii(p,q)) );
        }

        sort( graph.begin(), graph.end() );
        init(n);

        for( int i=0;i<graph.size();i++ )
        {
            int p,q,w;

            p= graph[i].s.f;
            q= graph[i].s.s;
            w= graph[i].f;

            int u= find_par(p);
            int v= find_par(q);

            if( u!=v )
            {
                parent[u]= v;
                dist[v]= w;
                dist[u]= w;
                adj[p].push_back(q);
                adj[q].push_back(p);
                cost[p].push_back(w);
                cost[q].push_back(w);
            }
        }

        memset( par, -1, sizeof(par) );
        Max[1][0]= 0;
        dfs(1,1,-1);
        table( n );

        printf("Case %d:\n", t);

        int q;
       // scanf("%d", &q);

        getchar();

        while(q--)
        {
            int a,b;
            scanf("%d %d", &a, &b);
            printf("%d\n", query( n,a,b ) );
        }
    }
}
