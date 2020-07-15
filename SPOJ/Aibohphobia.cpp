#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int dp[6110][6110];
bool vis[6110][6110];
char s[6110];

int rec( int l, int r )
{
    if(l>=r)
        return 0;
    if( vis[l][r] )
        return dp[l][r];

    int q1= inf, q2= inf, q3= inf;

    if( s[l]==s[r] )
        q1= rec(l+1,r-1);
    else
    {
        q2= 1+rec( l+1, r );
        q3= 1+rec( l, r-1 );
    }

    vis[l][r]= 1;

    return dp[l][r]= min( q1, min(q2,q3) );
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        scanf("%s", s);

        cout<< rec( 0, strlen(s)-1 ) <<endl;

        memset( vis, 0, sizeof(vis) );
    }
}

