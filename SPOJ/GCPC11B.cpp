#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010], vis[1010][1010];
int n,p;
string s,t;

int rec( int i, int j )
{
    if( i>=n or j>=n )
        return 0;

    if( vis[i][j]==p )
        return dp[i][j];

    int ret;

    if( abs(s[i]-t[j])<=1 )
        ret=1+ rec( i+1, j+1 );
    else
        ret= max( rec( i+1, j ), rec( i, j+1 ) );

    vis[i][j]= p;

    return dp[i][j]= ret;
}


int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        p++;

        cin>>n;
        cin>>s>>t;

        int l= rec( 0,0 );

        if( l>=n/2 )
            cout<<"POSITIVE\n";
        else
            cout<<"NEGATIVE\n";
    }
}
