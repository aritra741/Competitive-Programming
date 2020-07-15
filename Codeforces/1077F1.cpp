#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

ll dp[207][207][207];
bool vis[207][207][207];
ll arr[207];
int n,k,x;

ll rec( int i, int last, int baki )
{
    if( i>n )
        return 0;
    if( vis[i][last][baki] )
        return dp[i][last][baki];

    ll ret= -inf;

    if( baki )
        ret= max( ret, arr[i]+rec( i+1, i, baki-1 ) );
    if( i-last<k )
        ret= max( ret, rec( i+1, last, baki ) );

    if( i-last>=k and !baki )
        return -inf;

    vis[i][last][baki]= 1;

    return dp[i][last][baki]= ret;
}

int main()
{
    cin>>n>>k>>x;

    for( int i=1;i<=n;i++ )
        cin>>arr[i];

    cout<< max( -1LL, rec( 1, 0, x ) ) <<endl;
}
