#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n;
int dp[507][155257];

int rec( int i, int suma )
{
    int tot= i*(i-1);
    tot/= 2;

    if( i>n )
        return suma==tot-suma;

    if( dp[i][suma]!=-1 )
        return dp[i][suma];

    int ret= rec( i+1, suma+i );
    ret= ( ret+rec( i+1, suma ) )%mod;

    return dp[i][suma]= ret;
}

int main()
{
    memset( dp, -1, sizeof(dp) );

    cin>>n;

    cout<< (1LL*rec(1,0)*500000004)%mod <<endl;
}
