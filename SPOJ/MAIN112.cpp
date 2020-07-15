#include <bits/stdc++.h>
using namespace std;

int arr[20], dp[33000][20], vis[33000][20];
int cost[20];
int done, n, p;

int rec( int mask, int prev )
{
    if( mask==done )
        return 0;
    if( vis[mask][prev]==p )
        return dp[mask][prev];

    int pos= __builtin_popcount(mask);

    int ret= 1e9;
    for( int i=0; i<n; i++ )
        if( !(mask&(1<<i)) )
        {
            int c= 0, num= 0;
            if( mask )
                c= cost[pos], num= arr[prev];
            ret= min( ret,  abs(arr[i]-num)*c+ rec( mask|(1<<i), i ) );
        }

    vis[mask][prev]= p;

    return dp[mask][prev]= ret;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        p++;

        scanf("%d", &n);
        done= (1<<n)-1;

        for( int i=0;i<n;i++ )
            scanf("%d", &arr[i]);
        for( int i=0;i<n;i++ )
            scanf("%d", &cost[i]);

        printf("%d\n", rec( 0, 0 ) );
    }
}
