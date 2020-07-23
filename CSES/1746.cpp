#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int n,m;
int arr[100007];
int dp[100007][107];

int rec( int i, int last )
{
    if( i>=n )
        return 1;
    if( dp[i][last]!=-1 )
        return dp[i][last];

    int ret;

    if( arr[i] )
    {
        if( last and abs(last-arr[i])>1 )
            return 0;

        ret= rec( i+1, arr[i] );
    }
    else
    {
        ret= rec( i+1, last );
        if( last-1>=1 )
            ret= ( ret+rec( i+1, last-1 ) )%mod;
        if( last+1<=m )
            ret= ( ret+rec( i+1, last+1 ) )%mod;
    }

    return dp[i][last]= ret;
}

int main()
{
    memset( dp, -1, sizeof(dp) );

    cin>>n>>m;

    for( int i=0;i<n;i++ )
        cin>> arr[i];

    int ans= 0;
    if( arr[0] )
        ans= rec( 0, 0 );
    else
        for( int i=1;i<=m;i++ )
            ans= ( ans+rec( 1, i ) )%mod;

    cout<< ans <<endl;
}
