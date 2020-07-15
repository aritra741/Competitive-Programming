#include <bits/stdc++.h>
using namespace std;

int arr[30][30];
bool dp[30][30][30][30];
char c;

int ans;

int main()
{
    int n,m;
    cin>>n>>m;

    for( int i=0; i<n; i++ )
        for( int j=0; j<m; j++ )
            cin>> c, dp[i][j][i][j]= c-'0';

    if( !arr[0][0] )
        dp[0][0][0][0]= 1;

//    for( int i=0; i<n; i++ )
//        for( int j=1; j<m; j++ )
//            dp[0][i][0][j]= dp[0][i][0][j-1] and !arr[0][j],
//                            ans= max( ans, (dp[0][i][0][j])?2*(j-i+2):0 );
//
//    for( int i=0; i<n; i++ )
//        for( int j=1; j<m; j++ )
//            dp[i][0][j][0]= dp[i][0][j-1][0] and !arr[j][0],
//                            ans= max( ans, (dp[i][0][j][0])?2*(j-i+2):0 );

    for( int i=1; i<n; i++ )
        for( int j=1; j<m; j++ )
            for( int k=i+1; k<n; k++ )
                for( int l=j+1; l<m; l++ )
                {

                    if( k-1>=0 and k-1>=i )
                        dp[i][j][k][l]&= dp[i][j][k-1][l];
                    if( l-1>=0 and l-1>=j )
                        dp[i][j][k][l]&= dp[i][j][k][l-1];

                    if( dp[i][j][k][l] )
                        ans= max( ans, 2*(k-i+l-j+2) );
                    cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][k][l]<<endl;
                }

    cout<< ans <<endl;

}
