#include <bits/stdc++.h>
#define ll long long
#define mod 100000000
using namespace std;

ll dp[105][105][11][11];
bool vis[105][105][11][11];
int n, tot1, tot2, con1, con2;

ll rec( int n1, int n2, int k1, int k2 )
{
    if(n1>tot1)
        return 0;
    if( n2>tot2 )
        return 0;
    if( n1+n2==n )
        return 1;
    if( vis[n1][n2][k1][k2] )
        return dp[n1][n2][k1][k2];

    ll ans= 0;

    if( k1<con1 )
        ans= rec( n1+1, n2, k1+1, 0 )%mod;
    if( k2<con2 )
        ans= ( ans+ rec( n1, n2+1, 0, k2+1 )%mod )%mod;

    vis[n1][n2][k1][k2]= 1;

    return dp[n1][n2][k1][k2]= ans%mod;
}

int main()
{
    cin>>tot1>>tot2>>con1>>con2;

    n= tot1+tot2;

    cout<< rec( 0, 0, 0, 0 ) <<endl;
}
