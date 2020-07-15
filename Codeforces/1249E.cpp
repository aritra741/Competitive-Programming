#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[200007], b[200007];
ll ans[200007];
ll dp[200007][2];
ll n,c,p;

ll rec( int i, bool way )
{
    if( i<=0 )
        return 0;
    if( dp[i][way]!=-1 )
        return dp[i][way];

    ll ret= 2e18;

    if( way==0 )
    {
        ret= a[i]+rec(i-1,way);
        ret= min( ret, c+b[i]+rec(i-1,!way) );
    }
    else
    {
        ret= a[i]+rec( i-1, !way );
        ret= min( ret, b[i]+rec(i-1, way) );
    }

    return dp[i][way]= ret;
}

int main()
{
    memset( dp, -1, sizeof(dp) );
    cin>>n>>c;

    for( int i=1;i<=n-1;i++ )
        cin>>a[i];
    for( int i=1;i<=n-1;i++ )
        cin>>b[i];

    for( int i=n-1;i>=0;i-- )
        ans[i]= rec(i,0);

    for( int i=0;i<n;i++ )
        cout<<ans[i]<<" ";
}
