#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];
bool vis[1010][1010];
string s;

int rec( int l, int r )
{
    if(l>=r)
        return 0;
    if(vis[l][r])
        return dp[l][r];

    int q1,q2=2000,q3=2000;

    if(s[l]==s[r])
    {
        q1= rec( l+1, r-1 );
    }

    else
    {
        q1= 1+rec( l, r-1 );
        q2= 1+rec( l+1, r );
        q3= 1+rec( l+1, r-1 );
    }

    vis[l][r]= 1;

    return dp[l][r]= min( q1, min( q2,q3 ) );
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        cin>>s;

        cout<<"Case "<<t<<": "<< rec( 0, s.size()-1 ) <<endl;

        memset( vis, 0, sizeof(vis) );
    }
}
