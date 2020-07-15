#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[35][4][4];
int vis[35][4][4];
int n,p;

ll rec( int i, int p1, int p2 )
{
    if( i>=n )
        return 1LL;
    if( vis[i][p1][p2]==p )
        return dp[i][p1][p2];

    ll ret= 0;

    if( p1!=p2 )
    {
        if( p1+p2==3 and p1 and p2 )
            ret+= rec( i+1, 1, p1 ),
            ret+= rec( i+1, 2, p1 );
        else if( p1+p2==4 )
            ret+= rec( i+1, 1, p1 ),
            ret+= rec( i+1, 3, p1 );
        else if( p1+p2==5 )
            ret+= rec( i+1, 2, p1 ),
            ret+= rec( i+1, 3, p1 );
        else
        {
            ret+= rec( i+1, 1, p1 );
            ret+= rec( i+1, 2, p1 );
            ret+= rec( i+1, 3, p1 );
        }
    }

    else
    {
        ret+= rec( i+1, 1, p1 );
        ret+= rec( i+1, 2, p1 );
        ret+= rec( i+1, 3, p1 );
    }

    vis[i][p1][p2]= p;

    return dp[i][p1][p2]= ret;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        p++;
        cin>>n;

        cout<< rec( 0,0,0 ) <<endl;
    }
}
