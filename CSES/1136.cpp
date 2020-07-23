#include<bits/stdc++.h>
#define mx 200007
#define LN 17
using namespace std;

vector<int>adj[mx];
int lvl[mx], par[mx][LN+5];
int ans[mx];
int n;

void dfs( int u, int p )
{
    for( auto v: adj[u] )
        if( v!=p )
        {
            lvl[v]= lvl[u]+1;
            par[v][0]= u;
            dfs( v, u );
        }
}

void dfs2( int u, int p )
{
    for( auto v: adj[u] )
    {
        if(v==p)
            continue;

        dfs2( v, u );
        ans[u]+= ans[v];
    }
}

void build_table()
{
    par[1][0]= 0;

    for( int j=1; j<=LN; j++ )
        for( int i=1; i<=n; i++  )
            if( par[i][j-1]!=0 )
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

    int q;
    cin>>n>>q;

    for( int i=1;i<n;i++ )
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,1);
    build_table();

    while(q--)
    {
        int u,v;
        cin>>u>>v;

        int lca= LCA( u,v );

        ans[u]++;
        ans[v]++;
        ans[lca]--;
        ans[par[lca][0]]--;
    }

    dfs2(1,1);

    for( int i=1;i<=n;i++ )
        cout<< ans[i] <<" ";
}
