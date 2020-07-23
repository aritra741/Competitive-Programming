#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int dp[1000007];
int n;

int rec( int x )
{
    if( x>n )
        return 0;
    if( x==n )
        return 1;
    if( dp[x]!=-1 )
        return dp[x];

    int ret= 0;

    for( int i=1;i<=6;i++ )
        ret= ( ret+rec( x+i ) )%mod;

    return dp[x]= ret;
}

int main()
{
    memset( dp, -1, sizeof(dp) );

    cin>>n;

    cout<< rec( 0 ) <<endl;
}
