#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

ll f[1001], inv[1001];
vector<ll>primes;

ll bigmod( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (x*res)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res;
}

void init()
{
    f[0]= f[1]= inv[1]= 1;

    for( ll i=2; i<1001; i++ )
        f[i]= ( f[i-1]*i )%mod,
              inv[i]= bigmod( f[i], mod-2 );
}

map<ll,ll>mp;

int main()
{
    init();

    ll d;
    scanf("%lld", &d);

    for( ll i=2; i*i<=d; i++ )
        if( d%i==0 )
        {
            primes.push_back(i);
            while(d%i==0)
                d/= i;
        }

    int q;
    scanf("%d", &q);

    while(q--)
    {
        ll x, y;
        scanf("%lld %lld", &x, &y);

        ll g= __gcd( x,y );
        ll p= x/g;
        ll q= y/g;
        ll val= 1;
        ll tot= 0;

        for( auto x: primes )
        {
            ll i= x;
            if( p%i==0 )
            {
                int cc= 0;
                while( p%i==0 )
                    p/= i, cc++;
                val= ( val*inv[cc] )%mod;
                tot+= cc;
            }
        }

        if( p>1 )
        {
            val= ( val*inv[1] )%mod;
            tot++;
        }

        val= ( val*f[tot] )%mod;
        ll ans= val;
        val= 1;
        tot= 0;

        for( auto x: primes )
        {
            ll i= x;

            if( q%i==0 )
            {
                int cc= 0;
                while( q%i==0 )
                    q/=i, cc++;
                val= ( val*inv[cc] )%mod;
                tot+= cc;
            }
        }

        if( q>1 )
        {
            val= ( val*inv[1] )%mod;
            tot++;
        }

        val= ( val*f[tot] )%mod;
        ans= (ans*val)%mod;

        printf("%lld\n", ans);
    }
}
