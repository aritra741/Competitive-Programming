#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[30][160];
bool vis[30][160];

int n,x;

ll Pow( ll x, ll y )
{
    ll ans= 1;

    while( y>0 )
    {
        if(y&1)
            ans=ans*x;
        x=x*x;
        y=y>>1;
    }

    return ans;
}

ll rec( int i, int tot )
{
    if(i>=n)
    {
        if( tot>=x )
            return 1;
        return 0;
    }

    if(vis[i][tot])
        return dp[i][tot];

    ll q1= 0;

    for(int j=1; j<=6; j++)
        q1+= rec( i+1, tot+j );

    vis[i][tot]= 1;

    return dp[i][tot]= q1;

}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        scanf("%d %d", &n, &x);

        ll a= rec( 0, 0 );
        ll b= Pow( 6, n );
        ll g= __gcd( a,b );

        a/=g;
        b/=g;

        printf("Case %d: %lld", t, a);

        if( a!=0 and b!=1  )
            printf("/%lld", b);
        printf("\n");

        memset(vis, 0, sizeof( vis ));
    }
}
