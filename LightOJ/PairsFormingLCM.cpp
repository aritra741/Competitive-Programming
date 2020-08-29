#include <bits/stdc++.h>
#define ll long long
#define mx 10000007
using namespace std;

bool arr[mx];
vector<ll> prime;

void sieve()
{
    arr[0]=arr[1]=1;
    prime.push_back(2);

    for(ll i=3; i<mx; i+=2)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            for(ll j= i*i; j<mx; j+=i)
                arr[j]= 1;
        }
    }
}

int main()
{
    sieve();
    int sz= prime.size();

    int tc;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++)
    {
        ll n;
        scanf("%lld", &n);

        ll ans= 1;

        for(int i=0; i<sz and (ll)prime[i]*prime[i]<=n; i++ )
        {
            int cnt= 0;

            while( n%prime[i]==0 )
                n/=prime[i],
                   cnt++;
            ans*= 2*cnt+1;
        }

        if(n>1)
            ans*=3;

        printf("Case %d: %lld\n", t, (ans+1)/2);
    }
}
