#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define MX 1000007
#define d(x) cout<<endl<<x<<endl
using namespace std;

bool arr[MX];
vector <ll> prime;
vector <ll> v, dv;
vector <pll> pairs;
vector <ll> inter;

void sieve()
{
    arr[0]=arr[1]=1;

    for(ll i=2; i<MX; i++)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            for(ll j=i*i; j<MX; j+=i)
                arr[j]=1;
        }
    }
}

int main()
{
    sieve();
    ll n, a,b, ans=0;
    scanf("%lld", &n);

    for(int i=0; i<n; i++)
    {
        ll p,q;
        scanf("%lld %lld", &p,&q);

        pairs.push_back( pll(p,q) );

        a=p,b=q;
    }

    ll sz=prime.size();
    ll sqmx=max(a,b);
    dv.push_back(a);
    dv.push_back(b);

    for(ll i=0; i<sz and prime[i]<=sqmx; i++)
    {
        ll v=prime[i];
        while(a%v==0 and a!=v)
            {
                dv.push_back(v);
                dv.push_back(a/v);
                a/=v;
            }
        while(b%v==0 and b!=v)
            {
                dv.push_back(v);
                dv.push_back(b/v);
                b/=v;
            }

    }

    sort(dv.begin(), dv.end());

    bool flag=0;
    ll p,q;
    for(ll i=0; i<n; i++)
    {
        sz=dv.size();
        if(sz==0)
            break;
        p= pairs[i].first;
        q= pairs[i].second;


        for(ll j=0; j<sz; j++)
        {
            if(p%dv[j]==0 or q%dv[j]==0)
                inter.push_back(dv[j]);
        }

        sort(inter.begin(), inter.end());
        dv=inter;
        inter.clear();
    }

    if(dv.size())
        printf("%lld", dv[0]);
    else
        printf("-1");

}
