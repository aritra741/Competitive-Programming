#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
    ll res= 1%m;

    while(y>0)
    {
        if( y&1 )
            res= mulmod( res,x,m );
        x= mulmod( x,x,m );
        y>>= 1;
    }

    return res%m;
}

bool isPrime(ll n)
{
    if( n==1 )
        return 0;
    if( n==2 )
        return 1;
    ll d = n - 1;
    int s = 0;

    while (d % 2 == 0)
    {
        s++;
        d >>= 1;
    }

    // It's guranteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)
    int a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };

    for( int i=0; i<9; i++ )
        if( n==a[i] )
            return 1;

    for(int i = 0; i < 9; i++)
    {
        bool comp = bigmod(a[i], d, n) != 1;
        if(comp)
            for(int j = 0; j < s; j++)
            {
                ll fp = bigmod(a[i], (1LL << (ll)j)*d, n);
                if (fp == n - 1)
                {
                    comp = false;
                    break;
                }
            }
        if(comp)
            return false;
    }
    return true;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        ll n;
        scanf("%lld", &n);

        if( isPrime(n) )
            printf("%lld is a prime\n", n);
        else
            printf("%lld is not a prime\n", n);
    }
}

