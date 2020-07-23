#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

string s,t;

int dp[5007][5007];

int rec( int i, int j )
{
    if( i==-1 and j==-1 )
        return 0;
    if( i==-1 )
        return j+1;
    if( j==-1 )
        return i+1;

    if( dp[i][j]!=-1 )
        return dp[i][j];

    int ret= inf;

    if( s[i]==t[j] )
        ret= rec( i-1, j-1 );
    else
        ret= 1+min( rec( i-1, j ), min( rec( i, j-1 ), rec( i-1, j-1 ) ) );

    return dp[i][j]= ret;
}

int main()
{
    memset( dp, -1, sizeof(dp) );

    cin>>s;
    cin>>t;

    cout<< rec( s.size()-1, t.size()-1 ) <<endl;
}
