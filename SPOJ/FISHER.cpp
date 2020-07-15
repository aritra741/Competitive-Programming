#include <bits/stdc++.h>
using namespace std;

int tmb[55][55], toll[55][55], dp[55][1010];

int main()
{
    int n,t;

    while( cin>>n>>t and n+t )
    {
        memset( tmb, 0x3f, sizeof(tmb) );
        memset( toll, 0x3f, sizeof(toll) );
        memset( dp, 0x3f, sizeof(dp) );

        for( int i=0; i<n; i++ )
            for( int j=0; j<n; j++ )
                cin>> tmb[i][j];

        for( int i=0; i<n; i++ )
            for( int j=0; j<n; j++ )
                cin>> toll[i][j];

        dp[0][0]= 0;
        for( int i=0; i<=t; i++ )
            for( int k=0; k<n; k++ )
                for( int j=0; j<n; j++ )
                    if( tmb[k][j]<=i )
                        dp[j][i]= min( dp[j][i], toll[k][j]+dp[k][ i-tmb[k][j] ] );

        int mn= 2e9, T= -1;
        for( int i=0; i<=t; i++ )
            if( dp[n-1][i]<mn )
            {
                mn= dp[n-1][i];
                T= i;
            }

        cout<< mn <<" "<< T <<endl;
    }
}
