#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000LL
using namespace std;

ll dp[5007][5007];
ll arr[5007], sum[5007];
int n,m,k;
ll ans;

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    for( int i=1;i<=n;i++ )
        scanf("%lld", &arr[i]), sum[i]= sum[i-1]+arr[i];

    for( int i=n;i>=1;i-- )
        for( int j=1;j<=k;j++ )
        {
            if( (n-i+1)<j*m )
                continue;
            dp[i][j]= dp[i+1][j];
            if( i+m-1<=n )
                dp[i][j]= max( dp[i][j], sum[i+m-1]-sum[i-1]+dp[i+m][j-1] );

            if( dp[i][j]>ans )
                ans= dp[i][j];
        }

    printf("%lld\n", dp[1][k]);
}
