#include<bits/stdc++.h>
using namespace std;

int val[507][507]; /// val[l][r]= the value we get if we can shrink the [l,r] segment
int dp[507][507];  /// dp[l][r]= minimum length of segment there can be in [l,r] after shrinking

int main()
{
    int n;
    cin>>n;

    int arr[n+5];

    for( int i=1; i<=n; i++ )
        cin>>arr[i];

    memset( dp, 0x3f, sizeof(dp) );

    for( int i=1; i<=n; i++ )
        val[i][i]= arr[i], dp[i][i]= 1;

    for( int seg=2; seg<=n; seg++ )
    {
        for( int l=1; l<=n-seg+1; l++ )
        {
            int r= l+seg-1;

            for( int k=l; k<r; k++ )
            {
                if( val[l][k] and val[l][k]==val[k+1][r] )
                    val[l][r]= val[l][k]+1,
                    dp[l][r]= 1;
                else
                    dp[l][r]= min( dp[l][r], dp[l][k]+dp[k+1][r] );
            }
        }
    }

    cout<< dp[1][n] <<endl;
}
