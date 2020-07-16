#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll dp[2][200007];

int main()
{
    ll r,g;
    cin>>r>>g;

    dp[0][0]= 1;

    int st= 0;

    for( ll h=1;(h*(h+1))/2<=r+g;h++ )
    {
        st^= 1;

        for( int i=0;i<=r;i++ )
            dp[st][i]= 0;

        for( int i=0;i<=r;i++ )
        {
            int gg= (h*(h+1))/2-i;

            if(gg<0 or gg>g)
                continue;

            dp[st][i]= ( dp[st][i]+dp[!st][i] )%mod;

            if( i-h>=0 )
                dp[st][i]= ( dp[st][i]+dp[!st][i-h] )%mod;
        }
    }

    ll ans= 0;

    for( int i=0;i<=r;i++ )
        ans= ( ans+dp[st][i] )%mod;

    cout<< ans <<endl;
}



