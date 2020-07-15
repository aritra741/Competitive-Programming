#include <bits/stdc++.h>
#define inf 1e8
using namespace std;

int dp[1010][1010];
bool vis[1010][1010];
string s,t;

int rec( int m, int n )
{
    if(m<0 or n<0)
        return 0;
    if(vis[m][n])
        return dp[m][n];

    int q1= -inf, q2= -inf, q3= -inf;

    if( s[m]==t[n] )
        q1= 1+rec( m-1, n-1 );
    else
    {
        q2= rec( m-1, n );
        q3= rec( m, n-1 );
    }

    vis[m][n]= 1;

    return dp[m][n]= max( q1, max(q2,q3) );
}

int main()
{
    while(getline(cin,s))
    {
        getline(cin,t);
        cout<< rec( s.size()-1, t.size()-1 )<<endl;

        memset( vis, 0, sizeof(vis) );
    }
}
