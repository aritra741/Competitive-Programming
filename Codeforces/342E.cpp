#include<bits/stdc++.h>
#define LN 17
#define mx 100007
using namespace std;

vector<int>adj[mx];
int ans[mx], sub[mx], lvl[mx];
int par[mx][LN+5], cenpar[mx];
bool done[mx];
int n,m;
int subtree_sz;

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

int upore_tulbo(int u, int diff)
{
    for(int i=0; i<LN; i++)
        if( (diff>>i)&1 )
            u = par[u][i];

    return u;
}

int dist( int u, int v, int lca )
{
    return lvl[u]+lvl[v]-2*lvl[lca];
}

void set_subtree_size(int u,int pre)
{
    subtree_sz++;
    sub[u]=1;
    for(auto v:adj[u]){
        if(v==pre||done[v]) continue;
        set_subtree_size(v,u);
        sub[u]+=sub[v];
    }
}

int get_centroid(int u,int pre)
{
    for(auto v:adj[u])
    {
        if(v==pre||done[v])
            continue;
        else if(sub[v]>subtree_sz/2)
            return get_centroid(v,u);
    }
    return u;
}
void decompose(int u,int pre)
{
    subtree_sz=0;
    set_subtree_size(u,pre);
    int centroid=get_centroid(u,pre);
    cenpar[centroid]=pre;
    done[centroid]=1;
    for(auto v:adj[centroid])
    {
        if(v==pre||done[v])
            continue;
        decompose(v,centroid);
    }
}

void update( int u )
{
    int x= u;
    ans[u]= 0;

    while(u)
        ans[u]= min( ans[u], dist( u, x, LCA( u,x ) ) ), u= cenpar[u];
}

int query( int u )
{
    int ret= ans[u];
    int x= u;

    while(u)
        ret= min( ret, ans[u]+dist( u, x, LCA(u,x) ) ), u= cenpar[u];

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;

    for( int i=1; i<n; i++ )
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for( int i=1;i<=n;i++ )
        ans[i]= n+5;

    dfs( 1, 1 );

    build_table();
    decompose(1,0);

    update(1);

    while(m--)
    {
        int x,u;
        cin>>x>>u;

        if(x==1)
            update(u);
        else
            cout<< query(u) <<"\n";
    }
}
