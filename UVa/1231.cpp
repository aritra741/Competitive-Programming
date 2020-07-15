#include<bits/stdc++.h>
using namespace std;

int t,h,f;
int acorn[2007][2007];
int dp[2007][2007];
int h_max[2007];
int vis[2007][2007];
int pp;

int rec( int i, int hh )
{
    if( hh<0 )
        return 0;
    if( vis[i][hh]==pp )
        return dp[i][hh];

    int x= acorn[i][hh];
    int ret= x+rec( i, hh-1 );

    if( hh-f>=0 and h_max[hh]==-1 )
        for( int j=0; j<t; j++ )
        {
            h_max[hh]= max( h_max[hh], rec( j, hh-f ) );
        }

    if( hh-f>=0 )
        ret= max(ret,x+h_max[hh]);

    vis[i][hh]= pp;

    return dp[i][hh]= ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
        pp++;
        cin>>t>>h>>f;

        memset( h_max, -1, sizeof(h_max) );

        for( int i=0;i<t;i++ )
        {
            int x;
            cin>>x;

            for( int j=0;j<x;j++ )
            {
                int y;
                cin>>y;

                acorn[i][y]++;
            }
        }

        int ans= 0;

        for( int i=0;i<t;i++ )
            ans= max( ans, rec( i, h ) );

        cout<<ans<<"\n";

        memset( acorn, 0, sizeof(acorn) );
    }
}
