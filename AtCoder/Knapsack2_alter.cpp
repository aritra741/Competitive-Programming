
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100000*100+7];
ll weight[107], value[107];

int main()
{
    memset( dp, 0x3f, sizeof(dp) );

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,w;
    cin>>n>>w;

    ll tot_sum= 0;

    /// dp[i]-> minimum total weight by taking items with sum of value exactly i

    for( int i=0;i<n;i++ )
        cin>>weight[i]>>value[i], tot_sum+= value[i];

    dp[0]= 0;

    for( int i=0;i<n;i++ )
        for( int value_already=tot_sum-value[i];value_already>=0;value_already-- )
            dp[ value_already+value[i] ]= min( dp[ value_already+value[i] ], dp[ value_already ]+weight[i] );

    ll ans= 0;

    for( int i=0;i<=tot_sum;i++ )
        if( dp[i]<=w )
            ans= i;

    cout<< ans <<endl;
}
