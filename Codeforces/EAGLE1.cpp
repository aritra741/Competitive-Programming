#include<bits/stdc++.h>
#define mx 100007
#define ll long long
using namespace std;

vector<int>adj[mx], cost[mx];
ll dp[mx], f[mx], g[mx];

void dfsF( int u, int p )
{
    f[u]= 0;
    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];
        int w= cost[u][i];

        dfs( v, w );

        f[u]= max( f[u], f[v]+w );
    }
}

void remRoot(  )

int main()
{

}
