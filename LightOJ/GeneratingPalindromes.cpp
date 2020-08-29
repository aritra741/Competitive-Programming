#include <bits/stdc++.h>
using namespace std;

int dp[110][110];
bool vis[110][110];
string s;

int rec( int l, int r )
{
    if(l==r)
        return 0;
    if( r==l+1 )
    {
        if( s[l]==s[r] )
            return 0;
        return 1;
    }

    if(vis[l][r])
        return dp[l][r];

    int q1= 0, q2= 0;

    if(s[l]==s[r])
        q1= rec( l+1, r-1 );
    else
        q1= 1+rec( l+1, r );
    q2= 1+rec( l, r-1 );

    vis[l][r]= 1;

    return dp[l][r]= min( q1,q2 );
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        cin>>s;

        cout<<"Case "<<t<<": "<< rec( 0, s.size()-1 ) <<endl;

        memset(vis,0,sizeof(vis));
    }
}
