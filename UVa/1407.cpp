#include<bits/stdc++.h>
#define mx 507
using namespace std;

int par[mx];
int dp[mx][10007];
int vis[mx][10007];

int rec( int u, int p, int baki )
{
    if( vis[u][baki] )
        return dp[u][baki];

    int ret= 1;

    for( auto v: adj[u] )
    {

    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int n;
        scanf("%d", &n);

        int root= 0;

        for( int i=1;i<n;i++ )
        {
            int p,q;
            scanf("%d %d", &p, &q);

            adj[q].push_back(p);
            par[p]= q;
        }

        for( int i=0;i<n;i++ )
            if( par[i]==-1 )
                root= i;


    }
}
