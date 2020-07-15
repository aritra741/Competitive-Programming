#include<bits/stdc++.h>
using namespace std;

int dp[4194310][25][2];
int vis[4194310][25][2];
int n,m,pp;

int rec( int mask, int last, bool boro )
{
    if( __builtin_popcount(mask)==n )
        return 1;
    if( vis[mask][last][boro]==pp )
        return dp[mask][last][boro];

    int ret= 0;

    if( !mask )
        ret= rec( mask|(1<<m), m, 0 );
    else if( last==m )
    {
        if(!m)
        {
            for( int i=m+1;i<n;i++ )
                if( rec( mask|(1<<i), i, 0 ) )
                {
                    ret= rec( mask|(1<<i), i, 0 );
                    break;
                }
        }
        else
            for( int i=0;i<m;i++ )
                ret+= rec( mask|(1<<i), i, 1 );
    }
    else
    {
        for( int i=0;i<n;i++ )
        {
            if( boro and i>last and !(mask&(1<<i)) )
                ret+= rec( mask|(1<<i), i, 0 );
            else if( !boro and i<last and !(mask&(1<<i)) )
                ret+= rec( mask|(1<<i), i, 1 );
        }
    }

    vis[mask][last][boro]= pp;

    return dp[mask][last][boro]= ret;
}

int main()
{

    while( cin>>n>>m )
    {
        m--;
        pp++;

        cout<< rec( 0, 0, 1 ) <<endl;
    }
}
