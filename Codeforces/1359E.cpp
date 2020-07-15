#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define mx 500007
using namespace std;

ll f[mx], inv[mx];

ll bigmod( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res;
}

void init()
{
    f[1]= inv[1]= f[0]= inv[0]= 1;

    for( ll i=2;i<mx;i++ )
        f[i]= ( i*f[i-1] )%mod,
        inv[i]= bigmod( f[i], mod-2 );
}

int main()
{
    init();

    ll n,k;
    cin>>n>>k;

    ll ans= 0;

    for( ll i=1;i<=n;i++ )
    {
        ll divv= n/i;

        if(divv<k)
            continue;

        divv--;

        ll upore= f[divv];
        ll niche= ( inv[k-1]*inv[divv-k+1] )%mod;
        ll total= ( upore*niche )%mod;

        ans= ( ans+total )%mod;
    }

    cout<< ans <<endl;
}
