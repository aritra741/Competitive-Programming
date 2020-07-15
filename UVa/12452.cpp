#include<bits/stdc++.h>
#define mx 10007
using namespace std;

vector<int>adj[mx];

int dp[mx][2];
int vis[mx][2];
int pp;

int rec( int u, int p, int upore )
{
    if( dp[u][upore]!=-1 )
        return dp[u][upore];

    int pt= 0;  /// total cost of secured subtrees
    int npt= 0; /// total cost of unsecured subtrees

    for( auto v: adj[u] )
    {
        if(v==p)
            continue;

        pt+= rec( v, u, 1 );
        npt+= rec( v, u, 0 );
    }

    int ret= 2e9;

    if( upore )
    {
        int duita= 2e9, ekta= 2e9;

        for( auto v: adj[u] )
        {
            if( v!=p )
                ekta= min( ekta, dp[v][1]+100+npt-dp[v][0] );
            for( auto x: adj[u] )
                if( v!=x and x!=p )
                    duita= min( duita, dp[v][1]+dp[x][1]+175+npt-dp[v][0]-dp[x][0] );
        }

        ret= min( ekta, duita );
        ret= min( ret, npt );
        ret= min( ret, 500+pt );
    }
    else
    {
        int ch= 2e9;
        for( auto v: adj[u] )
        {
            if( v!=p )
                ch= min( ch, dp[v][1]+175+npt-dp[v][0] );
        }

        ret= min( ch, 100+npt );
        ret= min( ret, 500+pt );
    }

    return dp[u][upore]= ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        memset( dp, -1, sizeof(dp) );
        pp+=2;
        int n;
        scanf("%d", &n);

        for( int i=1;i<n;i++ )
        {
            int p,q;
            scanf("%d %d", &p, &q);

            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        printf("$%d\n", min( rec( 0, 0, 1 ), rec( 0, 0, 0 ) ) );

        for( int i=0;i<n;i++ )
            adj[i].clear();
    }
}
