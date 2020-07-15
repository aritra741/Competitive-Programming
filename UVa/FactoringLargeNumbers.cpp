#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MX 10000007
using namespace std;

bool arr[MX];
vector <ll> prime;
int sz;

void sieve()
{
    arr[0]=arr[1]=1;
    prime.push_back(2);

    for(ll i=3; i<MX; i+=2)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            for(ll j=i*i; j<MX; j+=i)
                arr[j]=1;
        }
    }
}

bool is_prime(ll m)
{
    if(m==1)
        return 0;

    ll sq= sqrt(m);

    for(int i=0;i<sz and prime[i]<=sq;i++)
    {
        if(m%prime[i]==0)
            return 0;
    }

    return 1;
}


int main()
{
    sieve();
    sz= prime.size();
    ll mx= prime[sz-1];

    while(1)
    {
        ll n;
        scanf("%lld", &n);

        if(n==-1)
            break;

        vector <ll> dv;
        ll sq= sqrt(n);

        for(int i=0;i<sz and prime[i]<=sq;i++)
            {
               // cout<<n<<endl;
                while(n%prime[i]==0)
                {
                    dv.push_back( prime[i] );

                    n/=prime[i];
                }
            }

        if( (n>sq or n>mx) and is_prime(n) )
                        dv.push_back( n );

        sort( dv.begin(), dv.end() );
        int z= dv.size();

        if(!z)
            printf("    %lld\n", n);
        else
        {
            for(int i=0;i<z;i++)
                printf("    %lld\n", dv[i]);
        }

        printf("\n");
    }
}
