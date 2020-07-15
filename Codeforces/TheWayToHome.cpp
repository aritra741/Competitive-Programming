#include <bits/stdc++.h>
using namespace std;

string s;
int n,d;
int dp[110];

int rec( int i )
{
    if( i==n-1 )
        return 0;

    if( dp[i]!=-1 )
        return dp[i];

    int ans= 1e9;
    for( int j=i+1;j<=i+d;j++ )
        if( s[j]=='1' )
            ans= min( ans, 1+rec( j ) );

    return dp[i]= ans;
}

int main()
{
    cin>>n>>d>>s;

    memset(dp,-1,sizeof(dp));

    int ans= rec( 0 );

    if( ans>n )
        cout<<"-1\n";
    else
        cout<<ans<<endl;
}
