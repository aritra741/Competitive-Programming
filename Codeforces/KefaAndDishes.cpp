#include <bits/stdc++.h>
#define ll long long
using namespace std;

int bef[20][20], sat[20];
ll dp[262144][20];
bool vis[262144][20];
int n,m,k;

ll rec( int mask, int last )
{
    if( __builtin_popcount(mask)==m )
        return 0;
    if( vis[mask][last] )
        return dp[mask][last];

    ll ans= 0;

    for(int i=0;i<n;i++)
    {
        if( mask&(1<<i) )
            continue;

        ans= max( ans, sat[i+1]+bef[last][i+1]+rec( mask|(1<<i), i+1 ) );
    }

    vis[mask][last]= 1;

    return dp[mask][last]= ans;
}

int main()
{
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
        cin>>sat[i];

    for(int i=0;i<k;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;

        bef[x][y]= c;
    }

    cout<< rec( 0, 0 ) <<endl;
}
