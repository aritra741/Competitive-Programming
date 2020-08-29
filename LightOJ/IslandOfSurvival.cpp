#include <bits/stdc++.h>
using namespace std;

double dp[1010][1010];

void init()
{
    for( int j=0;j<=1000;j++ )
        dp[0][j]= 1.00;

    dp[1][0]= 0.00;
    for( int i=1; i<=1000; i++ )
        for( int j=0; j<=1000; j++ )
        {
            if(i==1 and !j)
                continue;
            double nich= 1.00*(i+j+1)*(i+j)/2.0; /// Total meeting
            double upor= 0;

            if( j )
                nich-= j;   /// If people and deer meet, they don't contribute anything

            if( i>=2 )
                upor+= 1.00*i*(i-1)/2.00*dp[i-2][j];    /// Two tigers
            if( i and j )
                upor+= 1.00*i*j*dp[i][j-1];              /// Tiger and Deer
            if( j>=2 )
                nich-= 1.00*j*(j-1)/2.0;               /// Two deers don't contribute

            dp[i][j]= upor/nich;
        }
}

int main()
{
    init();
    int tc;
    cin>>tc;

    for( int T=1; T<=tc; T++ )
    {
        int t,c;
        cin>>t>>c;

        cout.precision(10);
        cout<<fixed<<"Case "<<T<<": "<< dp[t][c] <<endl;
    }
}
