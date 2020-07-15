#include <bits/stdc++.h>
using namespace std;

int n,m,w;
int b[1007], W[1007];
int par[1007], Size[1007];
int dp[1007][1007];
bool vis[1007][1007];
vector<int> cc[1007];

void init( int n )
{
    for( int i=1; i<=n; i++ )
        par[i]= i, Size[i]= 1;
}

int Find( int u )
{
    if( par[u]==u )
        return u;
    return par[u]= Find( par[u] );
}

int rec( int i, int c )
{
    if( c>w )
        return -2e9;
    if( i>n )
        return 0;
    if( vis[i][c] )
        return dp[i][c];

    int ret= rec( i+1, c );
    int totw= 0, totb= 0;

    for( int j=0; j<cc[i].size(); j++ )
    {
        int v= cc[i][j];
        totw+= W[v];
        totb+= b[v];

        ret= max( ret, b[v]+rec( i+1, c+W[v] ) );
    }

    ret= max( ret, totb+rec( i+1, totw+c ) );

    vis[i][c]= 1;

    return dp[i][c]= ret;
}

void unite( int u, int v )
{
    int paru= Find( u );
    int parv= Find( v );

    if( paru!=parv )
    {
        if( Size[paru]>Size[parv] )
            par[parv]= paru, Size[paru]+= Size[parv];
        else
            par[paru]= parv, Size[parv]+= Size[paru];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>w;

    init(n);

    for( int i=1; i<=n; i++ )
        cin>> W[i];
    for( int i=1; i<=n; i++ )
        cin>> b[i];

    for( int i=0; i<m; i++ )
    {
        int p,q;
        cin>>p>>q;

        unite( p,q );
    }

    for( int i=1; i<=n; i++ )
        cc[ Find(i) ].push_back( i );

    cout<< rec( 1, 0 ) <<endl;
}
