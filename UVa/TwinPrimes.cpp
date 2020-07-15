#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MX 20000000+7
using namespace std;

bool arr[MX];
vector <ll> prime;
vector <pll> twin;

void sieve()
{
    arr[0]=arr[1]=1;

    for(ll i=3;i<MX;i+=2)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            for(ll j=i*i;j<MX;j+=i)
                arr[j]=1;
        }
    }

    int sz= prime.size();


    for(int i=0;i<sz-1;i++)
    {
        if( prime[i]==prime[i+1]-2 )
        {
            twin.push_back( pll( prime[i], prime[i+1] ) );
        }
    }
}


int main()
{
    sieve();

    int n;

    while(cin>>n)
    {
        printf("(%lld, %lld)\n", twin[n-1].first, twin[n-1].second);
    }
}


















