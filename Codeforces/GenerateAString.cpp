#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,x,y;
ll dp[10000007];

int main()
{
    cin>>n>>x>>y;

    dp[0]= 0, dp[1]= x;

    for( int i=2;i<=n;i++ )
    {
        dp[i]= dp[i-1]+x;

        if( i&1 )
            dp[i]= min( dp[i], dp[(i+1)/2]+x+y );
        else
            dp[i]= min( dp[i], dp[i/2]+y );
    }

    cout<< dp[n] <<endl;

}
