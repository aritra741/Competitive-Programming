#include <bits/stdc++.h>
using namespace std;

int tmb[110][110], risk[110][110], dp[110][260];

int main()
{
    int tc;
    cin>>tc;

    while( tc-- )
    {
        int n,t;
        cin>>n>>t;

        memset( tmb, 0x3f, sizeof(tmb) );
        memset( risk, 0x3f, sizeof(risk) );
        memset( dp, 0x3f, sizeof(dp) );

        for( int i=0; i<n; i++ )
            for( int j=0; j<n; j++ )
                cin>> tmb[i][j];

        for( int i=0; i<n; i++ )
            for( int j=0; j<n; j++ )
                cin>> risk[i][j];

        dp[0][0]= 0;
        for( int i=0; i<=t; i++ )
            for( int k=0; k<n; k++ )
                for( int j=0; j<n; j++ )
                    if( tmb[k][j]<=i )
                        dp[j][i]= min( dp[j][i], risk[k][j]+dp[k][ i-tmb[k][j] ] );

        int mn= 2e9, T= -1;
        for( int i=0; i<=t; i++ )
            if( dp[n-1][i]<mn )
            {
                mn= dp[n-1][i];
                T= i;
            }

        if( mn>1e9 )
            cout<<"-1\n";
        else
            cout<< mn <<" "<< T <<endl;
    }
}

