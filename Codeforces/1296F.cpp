#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 5007
#define LN 14
using namespace std;

vector<int>adj[mx];
vector<pii>vv, ee;
int ans[mx];    /// ans[i]= value assigned to the edge between i and par[i]
int cost[mx];
int lvl[mx];
int par[mx][LN+7];
int n;

void dfs( int u, int pre )
{
    for( int i=0; i<adj[u].size(); i++ )
    {
        int v= adj[u][i];

        if(v!=pre)
        {
            lvl[v]= lvl[u]+1;
            par[v][0]= u;
            dfs( v, u );
        }
    }
}

void build_table()
{
    par[1][0]= 1;

    for( int j=1; j<=LN; j++ )
        for( int i=1; i<=n; i++  )
            if( par[i][j-1]!=-1 )
                par[i][j]= par[ par[i][j-1] ][j-1];
}

int LCA(int u, int v)
{
    if(lvl[u] < lvl[v])
        swap(u,v);
    int diff = lvl[u] - lvl[v];
    for(int i=0; i<LN; i++)
        if( (diff>>i)&1 )
            u = par[u][i];
    if(u == v)
        return u;
    for(int i=LN-1; i>=0; i--)
        if(par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }

    return par[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset( par, -1, sizeof(par) );

    cin>>n;

    for( int i=1; i<n; i++ )
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        ee.push_back( pii(u,v) );
    }

    dfs( 1, 1 );
    build_table();

    int q;
    cin>>q;

    for( int j=0; j<q;j++ )
    {
        int u,v,x;
        cin>>u>>v>>x;

        vv.push_back( pii(u,v) );
        cost[j]= x;

        int lca= LCA( u,v );

        while(u!=lca)
            ans[u]= max( ans[u], x ), u= par[u][0];
        while(v!=lca)
            ans[v]= max( ans[v], x ), v= par[v][0];
    }

    bool f= 1;

    for( int i=0; i<q; i++ )
    {
        int lagbe= cost[i];

        int u= vv[i].ff;
        int v= vv[i].ss;

        int lca= LCA( u,v );

        int mn= 1e6;

        while(u!=lca)
            mn= min( ans[u],mn ), u= par[u][0];

        while(v!=lca)
            mn= min( ans[v],mn ), v= par[v][0];

        if(mn>lagbe)
        {
            f= 0;
            break;
        }
    }

    if(!f)
        return cout<<"-1\n", 0;

    for( auto p: ee )
    {
        int u= p.ff;
        int v= p.ss;

        if( par[u][0]==v )
            swap( u,v );

        if(!ans[v])
            ans[v]= 1000000;

        cout<< ans[v] <<" ";
    }
}
