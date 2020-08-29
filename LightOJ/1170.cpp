#include<bits/stdc++.h>
#define mx 500007
#define mx2 10000000000
#define mod 100000007
#define ll long long
using namespace std;

ll f[mx], I[mx];
bool done[mx+107];
vector<ll>arr;

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
    f[0]= I[0]= 1;

    for( int i=1;i<mx;i++ )
        f[i]= (f[i-1]*i)%mod,
        I[i]= bigmod( f[i], mod-2 );

    for( ll i=2;i*i<=mx2;i++ )
    {
        if(i<mx and done[i])
            continue;
        ll j= i;

        while(j<=mx2)
        {
            j*= i, arr.push_back(j);

            if(j<mx)
                done[j]= 1;
        }
    }

    sort( arr.begin(), arr.end() );
}

int main()
{
    init();

    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        ll a,b;
        scanf("%lld %lld", &a, &b);

        int pos1= lower_bound( arr.begin(), arr.end(), a )-arr.begin();
        int pos2= upper_bound( arr.begin(), arr.end(), b )-arr.begin();
        ll tot= max(0LL,(ll)pos2-pos1);

        if( !tot )
        {
            printf("Case %d: 0\n", t);
            continue;
        }

        ll upore= f[tot*2];
        ll niche= (I[tot]*I[tot])%mod;
        niche= ( niche*bigmod( tot+1, mod-2 ) )%mod;

        ll ans= (upore*niche)%mod;

        printf("Case %d: %lld\n", t, ans);
    }
}
