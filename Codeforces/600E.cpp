#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
#define f first
#define s second
#define mx 100007
#define sf(x) scanf("%d", &x)
using namespace std;

int n;
vector<int> adj[mx];
unordered_map<int,int>mp[mx];
int par[mx], Size[mx];
bool vis[mx];
int cnt[mx];
ll ans[mx];
ll out[mx];

void init( int n )
{
    for( int i=0; i<=n; i++ )
        par[i]= i, Size[i]= 1;
}

int Find( int u )
{
    if( par[u]==u )
        return u;
    return par[u]= Find( par[u] );
}

void update( int node, int bar, int col )
{
    if( bar>cnt[node] )
        cnt[node]= bar, ans[node]= col;
    else if( bar==cnt[node] )
        ans[node]+= col;
}

void unite( int u, int v )
{
    int paru= Find( u );
    int parv= Find( v );

    if( paru!=parv )
    {
        if( Size[paru]>Size[parv] )
        {
            par[parv]= paru, Size[paru]+= Size[parv];

            for( auto x: mp[parv] )
                mp[paru][x.f]+= x.s, update( paru, mp[paru][x.f], x.f );
        }
        else
        {
            par[paru]= parv, Size[parv]+= Size[paru];

            for( auto x: mp[paru] )
                mp[parv][x.f]+= x.s, update( parv, mp[parv][x.f], x.f );
        }
    }
}

void dfs( int u )
{
    vis[u]= 1;

    for( auto v: adj[u] )
    {
        if(!vis[v])
            dfs(v), unite(u,v);
    }

    out[u]= ans[Find(u)];
}

int main()
{
    scanf("%d", &n);

    init(n);

    for( int i=1; i<=n; i++ )
    {
        int p;
        sf(p);

        cnt[i]++;
        ans[i]= p;
        mp[i][p]++;
    }

    for( int i=1; i<n; i++ )
    {
        int p,q;
        scanf("%d %d", &p,&q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    dfs(1);

    for( int i=1;i<=n;i++ )
        printf("%lld ", out[i]);
}
