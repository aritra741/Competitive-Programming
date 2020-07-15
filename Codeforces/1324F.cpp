#include<bits/stdc++.h>
#define mx 200007
using namespace std;

int dp[mx], arr[mx];
int ans[mx];
vector<int>adj[mx];

void dfs( int u, int pre )
{
    dp[u]= arr[u];
    for( auto v: adj[u] )
    {
        if(v==pre)
            continue;
        dfs(v, u);
        dp[u]+= max( 0, dp[v] );
    }
}

void dfs2( int v, int u )
{
    int tmp= dp[v];
    if(v!=u)
        dp[u]-= max( 0, dp[v] ),
        dp[v]+= max( 0, dp[u] ),
        dp[u]+= max( 0, tmp );
    ans[v]= dp[v];

    for( auto x: adj[v] )
    {
        if( x==u )
            continue;
        dfs2(x,v);
    }
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
        cin>> arr[i], arr[i]=(!arr[i])?-1:1;

    for( int i=1;i<n;i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    dfs(1,0);
    dfs2(1,1);

    for( int i=1;i<=n;i++ )
        cout<< ans[i] <<" ";
}
