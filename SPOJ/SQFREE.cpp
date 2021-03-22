#include<bits/stdc++.h>
#define ll long long
#define mx 10000007
using namespace std;

bool arr[mx];
int sign[mx];
int hit[mx];

// sign[i]= 0 -> Divisible by square of a prime
// sign[i]= 1 -> Contains even number of primes
// sign[i]=-1 -> Contains odd number of primes


void init()
{
    for( int i=0;i<mx;i++ )
        sign[i]= 1;

    for( ll i=2; i<mx; i++ )
    {
        if(!arr[i])
        {
            hit[i]++;
            for( ll j=i*2; j<mx; j+=i )
            {
                arr[j]= 1;
                hit[j]++;
                ll pp= j;

                pp/= i;

                if(pp%i==0)
                    sign[j]= 0;
            }
        }
    }

    for( ll i=2;i<mx;i++ )
    {
        if(!sign[i])
            continue;
        if(hit[i]&1)
            sign[i]= -1;
    }
}
int main()
{
    init();
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        ll n;
        scanf("%lld", &n);

        ll ans= 0;

        for( ll x=2;x*x<=n;x++ )
            ans-= sign[x]*(n/(x*x));

        printf("%lld\n", n-ans);
    }
}