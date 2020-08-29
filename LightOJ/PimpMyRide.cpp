#include <bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

int done, n;

int arr[20][20];
ll dp[16388];
bool vis[16388];

ll rec( int mask )
{
    if(mask==done)
        return 0;
    if(vis[mask])
        return dp[mask];

    ll ans= inf;

    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
            continue;

        ll tot= 0;

        for(int j=0;j<n;j++)
        {
            if( mask&(1<<j) )
                tot+=arr[i][j];
        }

        ans= min( ans, tot+arr[i][i]+rec( mask|(1<<i) ) );
    }

    vis[mask]= 1;

    return dp[mask]= ans;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        cin>>n;

        done= (1<<n)-1;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>arr[i][j];

        cout<<"Case "<<t<<": "<< rec(0) <<endl;

        memset(vis,0,sizeof(vis));
    }
}
