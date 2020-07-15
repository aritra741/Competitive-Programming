#include<bits/stdc++.h>
#define inf 2e9
using namespace std;

int dp[515][515];
int vis[515][515];
int arr[515];
int n,p;

int rec( int nokol, int ashol )
{
    if( __builtin_popcount(nokol)==9 )
    {
        if( __builtin_popcount(ashol)==9 )
            return 0;
        return -inf;
    }

    if( vis[nokol][ashol]==p )
        return dp[nokol][ashol];

    int ret= -inf;
    for( int i=0; i<9; i++ )
    {
        if( nokol&(1<<i) )
            continue;

        for( int j=i+1; j<9; j++ )
        {
            if( nokol&(1<<j) )
                continue;

            for( int k=j+1; k<9; k++ )
            {
                if(nokol&(1<<k))
                    continue;

                int now= 0;
                now|= 1<<i;
                now|= 1<<j;
                now|= 1<<k;

                int pore= ashol;

                if( arr[now] )
                    pore|= now;

                int ekhon= nokol|now;

                ret= max( ret, arr[now]+rec( ekhon, pore ) );
            }
        }
    }

    vis[nokol][ashol]= p;

    return dp[nokol][ashol]= ret;
}

int main()
{
    int tc= 1;
    while( scanf("%d", &n)==1 and n )
    {
        p++;
        for( int x=0; x<n; x++ )
        {
            int a,b,c,s;
            scanf("%d %d %d %d", &a, &b, &c, &s);

            int mask= 0;

            mask|= 1<<(a-1);
            mask|= 1<<(b-1);
            mask|= 1<<(c-1);

            arr[mask]= s;
        }

        printf("Case %d: %d\n", tc++, max(-1,rec( 0, 0 )) );

        memset( arr, 0, sizeof(arr) );
    }
}
