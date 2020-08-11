#include<bits/stdc++.h>
using namespace std;

int n;
string s,t;

bool vis[300007][4];
bool dp[300007][4];

bool rec( int i, int c, int aa, int bb, int cc )
{
    if( i>=3*n )
        return 1;
    if( vis[i][c] )
        return dp[i][c];

    bool ret= 0;

    if( !i )
        ret= rec( i+1, 1, aa-1, bb, cc ) or rec( i+1, 2, aa, bb-1, cc ) or rec( i+1, 3, aa, bb, cc-1 );

    else
        for( int j=1; j<=3; j++ )
        {
            if( c==s[0]-'a'+1 and j==s[1]-'a'+1 )
                continue;
            if( c==t[0]-'a'+1 and j==t[1]-'a'+1 )
                continue;

            if( j==1 and aa )
                ret|= rec( i+1, j, aa-1, bb, cc );
            if( j==2 and bb )
                ret|= rec( i+1, j, aa, bb-1, cc );
            if( j==3 and cc )
                ret|= rec( i+1, j, aa, bb, cc-1 );
        }

    vis[i][c]= 1;

    return dp[i][c]= ret;
}

void print( int i, int c, int aa, int bb, int cc )
{
    if(i>=n)
        return;

    if( aa and dp[i+1][1][aa-1][bb][cc] )
    {
        cout<<"a";
        print( i+1, 1, aa-1, bb, cc );
    }

    if( bb and dp[i+1][2][aa][bb-1][cc] )
    {
        cout<<"b";
        print( i+1, 2, aa, bb-1, cc );
    }
    if( cc and dp[i+1][3][aa][bb][cc-1] )
    {
        cout<<"c";
        print( i+1, 3, aa, bb, cc-1 );
    }
}

int main()
{
    cin>>n;
    cin>>s;
    cin>>t;

    if(!rec( 0, 0, n, n, n, ))
        return cout<<"NO\n", 0;

    cout<<"YES\n";
    print( 0, 0, n, n, n );
}
