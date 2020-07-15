#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int arr[107];
int sum[107][100007];
int dp[107][100007];

int main()
{
    int n,k;
    cin>>n>>k;

    for( int i=1;i<=n;i++ )
        cin>> arr[i];

    for( int i=1;i<=n;i++ )
    {
        dp[i][0]= 1;
        sum[i][0]= 1;
    }

    for( int i=0;i<=k;i++ )
        sum[0][i]= 1;

    for( int i=1;i<=n;i++ )
    {
        for( int j=1;j<=k;j++ )
        {
            int range,l,r;
            if( j-arr[i]-1>=0 )
                l=  sum[i-1][j-arr[i]-1];
            else
                l= 0;
            r= sum[i-1][j];

            dp[i][j]= ( dp[i][j]+( r-l+mod )%mod )%mod;
            sum[i][j]= ( sum[i][j-1]+dp[i][j] )%mod;
        }
    }

    cout<< dp[n][k] <<endl;
}
