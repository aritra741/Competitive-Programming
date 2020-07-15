#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[407], sum[407];
ll dp[407][407];
bool vis[407][407];

ll rec( int l, int r )
{
    if(l==r)
        return 0;
    if(l>r)
        return 1e18;
    if( vis[l][r] )
        return dp[l][r];

    ll ret= 1e18;

    for( int i=l;i<r;i++ )
        ret= min( ret, rec( l, i )+rec( i+1, r )+sum[r]-sum[l-1] );

    vis[l][r]= 1;

    return dp[l][r]= ret;
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
        cin>> arr[i], sum[i]= arr[i]+sum[i-1];

    cout<< rec( 1, n ) <<endl;
}
