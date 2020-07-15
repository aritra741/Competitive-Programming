#include<bits/stdc++.h>
#define mx 100007
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int>adj[mx];
int deg[mx], lvl[mx];
int ans= 1;
bool vis[mx];
int dp[mx];

int dfs( int u )
{
    if( vis[u] )
        return dp[u];

    dp[u]= 0;

    for( auto v: adj[u] )
        dp[u]= max( dp[u], dfs(v)+1);

    vis[u]= 1;

    return dp[u];
}

int main()
{
    FAST

    int n,m;
    cin>>n>>m;

    for( int i=0;i<m;i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        deg[q]++;
    }

    for( int i=1;i<=n;i++ )
        if( !deg[i] )
            ans= max( ans, dfs(i) );

    cout<<ans<<endl;
}
