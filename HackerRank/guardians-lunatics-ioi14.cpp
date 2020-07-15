#include<bits/stdc++.h>
#define inf 1e18
#define ll long long
using namespace std;

ll c[8007], sum[8007];
ll dp[807][8007];
bool vis[807][8007];

ll cost( ll l, ll r )
{
    return (sum[r]-sum[l-1])*( r-l+1 );
}

void rec( int g, int l, int r, int p1, int p2 )
{
    if(r<l)
        return;

    int mid= (l+r)/2;
    dp[g][mid]= inf;
    int opt= mid-1;

    for( int i=min(p2,mid);i>=p1;i-- )
    {
        if( dp[g][mid]>=dp[g-1][i]+cost( i+1, mid ) )
            dp[g][mid]= dp[g-1][i]+cost( i+1, mid ), opt= i;
    }

    rec( g, l, mid-1, p1, opt );
    rec( g, mid+1, r, opt, p2 );
}

int main()
{
    ll l,g;
    scanf("%lld %lld", &l, &g);

    for( int i=1;i<=l;i++ )
        scanf("%lld", &c[i]);

    for( int i=1;i<=l;i++ )
        sum[i]= sum[i-1]+c[i];

    for( int i=1;i<=l;i++ )
        dp[1][i]= cost(1,i);

    for( int i=2;i<=g;i++ )
    {
        rec( i, 1, l, 0, l );
    }
    printf("%lld\n", dp[g][l]);
}
