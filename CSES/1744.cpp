#include<bits/stdc++.h>
using namespace std;

int dp[507][507];

int rec( int a, int b )
{
    if( a==b )
        return 0;
    if( dp[a][b]!=-1 )
        return dp[a][b];

    int ret= 1e9;

    for( int i=1;i<a;i++ )
        ret= min( ret, 1+rec( i, b )+rec( a-i, b ) );
    for( int i=1;i<b;i++ )
        ret= min( ret, 1+rec( a, i )+rec( a, b-i ) );

    return dp[a][b]= ret;
}

int main()
{
    memset( dp, -1, sizeof(dp) );

    int a,b;
    cin>>a>>b;

    cout<< rec( a,b ) <<endl;
}
