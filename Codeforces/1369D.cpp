#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll dp[2000007];

int main()
{
    for( int i=3;i<2000007;i++ )
        dp[i]= ( dp[i-1]+2*dp[i-2]+4*( i%3?0:1 ) )%mod;

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        cout<< dp[n] <<endl;
    }
}

