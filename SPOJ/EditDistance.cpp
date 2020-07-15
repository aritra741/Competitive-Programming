#include <bits/stdc++.h>
using namespace std;

int dp[2010][2010];
bool vis[2010][2010];
string s,t;

int rec( int m, int n )
{
    if(m==-1)
        return n+1;
    if(n==-1)
        return m+1;

    if(vis[m][n])
        return dp[m][n];

    int q1, q2=3000, q3=3000;

    if(s[m]==t[n])
    {
        q1= rec(m-1,n-1);        ///Last character match kore, so we move on
    }

    else
    {
        q1= 1+rec( m-1, n );    ///Deleting from s
        q2= 1+rec( m, n-1 );    ///Inserting in s
        q3= 1+rec( m-1,n-1 );    ///Replacing from either of the strings
    }

    vis[m][n]= 1;

    return dp[m][n]= min( q1, min(q2,q3) );
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>s>>t;

        cout<< rec( s.size()-1, t.size()-1 ) <<endl;

        memset( vis, 0, sizeof(vis) );
    }
}
