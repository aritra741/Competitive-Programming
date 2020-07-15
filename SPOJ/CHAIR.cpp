#include <bits/stdc++.h>
#define ll long long
#define mod 1000000003
using namespace std;

ll n,k;
ll dp[1010][1010][2];
bool vis[1010][1010][2];

ll rec( int i, int cnt, bool fr )
{
    if( cnt==k )
        return 1LL;
    if( i==n-1 and fr )
        return 0;
    if( i>=n )
        return 0;

    if( vis[i][cnt][fr] )
        return dp[i][cnt][fr];

    ll ret= rec( i+1, cnt, fr )%mod;

    bool f= fr;

    if(!i)
        f= 1;

    ret= ( ret+rec( i+2, cnt+1, f ) );

    vis[i][cnt][fr]= 1;

    return dp[i][cnt][fr]= ret%mod;
}

int main()
{
    cin>>n>>k;

    cout<< rec( 0,0,0 ) <<endl;

}
