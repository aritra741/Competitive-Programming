#include <bits/stdc++.h>
using namespace std;

string s, t;
int n,m,k;

int dp[1010][1010][11][2];

int rec( int i, int j, int l, int match )
{
    if( i>=n )
        return 0;
    if( j>=m )
        return 0;
    int &ret= dp[i][j][l][match];

    if( ret!=-1 )
        return ret;

    int ans= 0;

    if( s[i]==t[j] )
    {
        if( match )
            ans= max( ans, 1+rec( i+1, j+1, l, match ) );
        if( l>=1 )
            ans= max( ans, 1+rec( i+1, j+1, l-1, 1 ) );
    }

    ans= max( ans, rec( i+1, j, l, 0 ) ),
    ans= max( ans, rec( i, j+1, l, 0 ) );

    return ret= ans;
}

int main()
{
    memset( dp, -1, sizeof(dp) );

    cin>>n>>m>>k;
    cin>>s>>t;

    cout<< rec( 0, 0, k, 0 ) <<endl;
}
