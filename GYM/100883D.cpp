#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[1000007];
ll n,k;

bool ok( ll x )
{
    ll cnt= 1;
    ll mx= 0, st= 0;

    for( int i=0;i<n;i++ )
    {
        if( arr[i]>x )
            return 0;
        mx= max( mx, arr[i] );

        if( (i-st+1)*mx>x )
            cnt++, mx= arr[i], st= i;
    }

    if(cnt<=k)
        return 1;
    return 0;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%lld %lld", &n, &k);

        for( int i=0;i<n;i++ )
            scanf("%lld", &arr[i]);

        ll l= 0, r= 1e13;
        ll ans= 1e13;

        while(r-l>5)
        {
            ll mid= (r+l)/2;

            if( ok(mid) )
                ans= mid, r= mid;
            else
                l= mid;
        }

        while( l<=r )
        {
            if( l<ans and ok(l) )
                ans= l;
            l++;
        }

        printf("%lld\n", ans);
    }
}
