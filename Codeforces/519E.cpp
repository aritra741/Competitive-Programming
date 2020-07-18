#include<bits/stdc++.h>
#define LN 17
#define mx 100007
using namespace std;

int n;
vector<int>adj[mx];
int par[mx][LN+1];
int lvl[mx], sub[mx];
int nicheu, nichev, lca;

void dfs( int u, int pre )
{
    sub[u]= 1;
    for( int i=0; i<adj[u].size(); i++ )
    {
        int v= adj[u][i];

        if(v!=pre)
        {
            lvl[v]= lvl[u]+1;
            par[v][0]= u;
            dfs( v, u );
            sub[u]+= sub[v];
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

    nicheu= u;
    nichev= v;

    return par[u][0];
}

int upore_tulbo(int u, int diff)
{
    for(int i=0; i<LN; i++)
        if( (diff>>i)&1 )
            u = par[u][i];

    return u;
}

int dist( int u, int v )
{
    return lvl[u]+lvl[v]-2*lvl[lca];
}

int main()
{
    cin>>n;

    for( int i=1; i<n; i++ )
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,1);
    build_table();

    int q;
    cin>>q;

    while(q--)
    {
        int u,v;
        cin>>u>>v;

        if( lvl[u]<lvl[v] )
            swap(u,v);

        lca= LCA( u,v );

        if(u==v)
        {
            cout<<n<<'\n';
            continue;
        }

        if( par[u][0]== v )
        {
            cout<<"0\n";
            continue;
        }

        if( lca!=v and dist(lca,u)==dist(lca,v) )
        {
            cout<< sub[lca]-sub[nicheu]-sub[nichev]+n-sub[lca]<<"\n";
        }
        else
        {
            if( dist(u,v)&1 )
                cout<<"0\n";
            else
            {
                int mid= dist( u,v )/2;
                int x= upore_tulbo( u,mid );
                int y= upore_tulbo( u,mid-1 );

                cout<< sub[x]-sub[y] <<"\n";
            }
        }
    }
}
