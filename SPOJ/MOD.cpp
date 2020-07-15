#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll, ll> mp;

ll mulmod(ll a, ll b, ll c)
{
    ll x = 0, y = a % c;
    while (b)
    {
        if (b & 1)
            x = (x + y) % c;
        y = (y << 1) % c;
        b >>= 1;
    }
    return x % c;
}

ll bigmod( ll x, ll y, ll m )
{
    ll res= 1;

    while(y>0)
    {
        if( y&1 )
            res= mulmod( res,x,m );
        x= mulmod(x,x,m);
        y>>= 1;
    }

    return res;
}

int main()
{
    ll a,m,b;

    while( scanf("%lld %lld %lld", &a, &m, &b)==3 and a+m+b )
    {
        ll n= sqrt( m )+1;
        ll an= bigmod( a, n, m );
        ll ans= 1e18;

        for( ll p=1, num= an;p<=n;p++ )
        {
            if( !mp.count( num ) )
                mp[ num ]= p;
            num= ( num*an )%m;
        }

        for( ll q=0, num= b;q<=n;q++ )
        {
            if( mp.count( num ) )
                ans= min( ans, n*mp[num]-q );
            num= ( num*a )%m;
        }

        if( bigmod( a, ans, m )!= b%m )
            printf("No Solution\n");
        else
            printf("%lld\n", ans);

        mp.clear();
    }
}
