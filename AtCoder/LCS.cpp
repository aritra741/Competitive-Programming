#include <bits/stdc++.h>
using namespace std;

int dp[3010][3010];
bool vis[3010][3010];
string s, t;
string ans;

int rec( int m, int n )
{
    if(m>=s.size() or n>=t.size())
        return 0;
    if(vis[m][n])
        return dp[m][n];

    int q1= 0, q2= 0, q3= 0;
    if( s[m]==t[n] )
        q1= 1+rec( m+1, n+1 );
    else
    {
        q2= rec( m+1, n );
        q3= rec( m, n+1 );
    }

    vis[m][n]= 1;

    return dp[m][n]= max( q1, max(q2,q3));
}

void gen( int i, int j )
{
    if( i>=s.size() or j>=t.size() )
        return;

    if( s[i]==t[j] )
    {
        ans.push_back( s[i] );
        gen( i+1, j+1 );
        return;
    }

    if( dp[i+1][j]>dp[i][j+1] )
    {
        gen( i+1, j );
        return;
    }

    gen( i, j+1 );
}

int main()
{
    cin>>s>>t;

    int pp= rec( 0, 0 );

    gen( 0,0 );

    cout<< ans <<"\n";
}
