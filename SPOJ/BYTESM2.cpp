#include<bits/stdc++.h>
#define inf 2e9
using namespace std;

int dp[110][110], vis[110][110], arr[110][110];
int r,c,p;

int rec( int i, int j )
{
    if( i>=r )
        return 0;
    if( j>=c )
        return 0;
    if( vis[i][j]==p )
        return dp[i][j];

    int q1= 0, q2= 0, q3= 0;
    int ret= 0;

    if( !i )
    {
        for( int k=0; k<c; k++ )
        {
            if( k )
                q1= arr[i][k]+rec( i+1, k-1 );
            if( k<c-1 )
                q2= arr[i][k]+rec( i+1, k+1 );
            q3= arr[i][k]+ rec( i+1, k );

            ret= max( ret, max( q1, max( q2,q3 ) ) );
        }
    }

    else
    {
        if( j )
            q1= arr[i][j]+rec( i+1, j-1 );
        if( j<c-1 )
            q2= arr[i][j]+rec( i+1, j+1 );
        q3= arr[i][j]+ rec( i+1, j );
    }

    ret= max( ret, max( q1, max( q2,q3 ) ) );

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
        cin>>r>>c;

        for( int i=0; i<r; i++ )
            for( int j=0; j<c; j++ )
                cin>> arr[i][j];

        int ans= rec( 0,0 );

        cout<< ans <<endl;
    }
}
