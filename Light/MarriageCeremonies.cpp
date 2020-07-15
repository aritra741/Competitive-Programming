#include <bits/stdc++.h>
using namespace std;

int dp[65600];
bool vis[65600];
int arr[17][17];
int done;
int n;

int rec( int mask )
{
    if(mask==done)
        return 0;

    int i= __builtin_popcount(mask);

    if( vis[mask] )
        return dp[mask];

    int ans= INT_MIN;

    for(int j=0; j<n; j++)
    {
        if( !(mask&(1<<j) ) )
        {
            ans= max( ans, arr[i][j]+rec( mask|(1<<j) ) );
        }
    }

    vis[mask]= 1;

    return dp[mask]= ans;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        cin>>n;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];

        done= (1<<n)-1;

        int ans= rec( 0 );

        printf("Case %d: %d\n", t, ans);

        memset( vis, 0, sizeof(vis) );
    }
}
