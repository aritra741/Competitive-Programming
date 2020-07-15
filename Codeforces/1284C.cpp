#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fact[300007];

ll bigmod( ll x, ll y, ll m )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x)%m;
        x= (x*x)%m;
        y>>= 1;
    }

    return res%m;
}

void init( ll n, ll m )
{
    fact[0]= 1;

    for( ll i=1;i<=n;i++ )
        fact[i]= (fact[i-1]*i)%m;
}

int main()
{
    ll n,m;
    cin>>n>>m;

    init(n,m);

    ll ans= 0;

    for( ll i=0;i<n;i++ )
    {
        ll pashe= (n-i)%m;
        ll majhe_tot= i-1;
        ll tot_upay= (fact[i+1]*pashe)%m;
        tot_upay= (tot_upay*fact[(n-(i+1)+1)])%m;
        ans= (ans+tot_upay)%m;
    }

    cout<<ans<<endl;
}
