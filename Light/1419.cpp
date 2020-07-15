#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll bigmod( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }
    return res;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int n,k;
        scanf("%d %d", &n, &k);

        ll ans= 0;

        for( int i=1;i<=n;i++ )
            ans=(ans+bigmod( k, __gcd(i,n) ))%mod;

        ll inv= bigmod(n,mod-2);

        ans= (ans*inv)%mod;

        printf("Case %d: %lld\n", t, ans);
    }
}
