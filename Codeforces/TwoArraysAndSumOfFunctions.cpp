#include <bits/stdc++.h>
#define ll long long
#define m 998244353LL
using namespace std;

ll a[200007], b[200007], v[200007];

int main()
{
    int n;
    scanf("%lld", &n);

    for( int i=0;i<n;i++ )
        scanf("%lld", &a[i]);
    for( int i=0;i<n;i++ )
        scanf("%lld", &b[i]);

    sort( b, b+n, greater<ll>() );

    for( int i=0;i<n;i++ )
        v[i]=(i+1)*1LL*(n-i)*a[i];

    sort( v, v+n );

    ll ans= 0;

    for( int i=0;i<n;i++ )
        ans= (( (v[i]%m)*(b[i]%m) )%m+ans)%m;

    printf("%lld\n", ans);
}
