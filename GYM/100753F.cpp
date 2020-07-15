
#include <bits/stdc++.h>
#define mx 1000007
#define ll long long
using namespace std;

bool arr[mx];
int prime[mx];
int cnt= 0;

ll sq( ll n )
{
    ll s= sqrt(n);

    if( (s-1)*(s-1)==n )
        return s-1;
    if( (s+1)*(s+1)==n )
        return s+1;
    return s;
}

void sieve()
{
    prime[cnt++]= 2;

    for( ll i=3; i<mx; i+=2 )
    {
        if(!arr[i])
        {
            prime[cnt++]= i;

            for( ll j=i*i; j<mx; j+=2*i )
                arr[j]= 1;
        }
    }
}

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
    sieve();

    ll n;
    scanf("%lld", &n);

    ll ans= 1;

    for( int i=0; i<cnt and prime[i]*prime[i]*prime[i]<=n; i++ )
    {
        ll p= 0;

        while(n%prime[i]==0)
            p++, n/= prime[i];

        ans*= p+1;
    }

    ll y= n;

    if( isPrime(y) )
        ans*= 2;        /// nijei prime, power= 1
    else if( sq(y)*sq(y)==y and isPrime( sq(y) ) )
        ans*= 3;        /// sqrt prime, power= 2
    else if(y>1)
        ans*= 4;        /// p*q=y. p,q 2tai prime, 2tar power= 1 kore

    printf("%lld\n", ans);
}
