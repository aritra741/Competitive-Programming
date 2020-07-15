#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

ll Pow( ll x, ll y )
{
    ll res= 1;

    while( y>0 )
    {
        if(y&1)
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res%mod;
}

int arr[100007];

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=0;i<n;i++ )
        scanf("%d", &arr[i]);

    ll ans= 0;

    for( int i=0;i<n;i++ )
    {
        ll cnt= -1;
        while( arr[i] )
        {
            ll p= arr[i]%10;
            arr[i]/= 10;

            ll pos1= cnt+1;
            ll pos2= cnt+2;

            ll tmp1= (((p*Pow( 10, pos1 ))%mod)*n)%mod;
            ll tmp2= (((p*Pow( 10, pos2 ))%mod)*n)%mod;

            ll tmp= ( tmp1+tmp2 )%mod;

            ans= ( ans+tmp )%mod;

            cnt+= 2;
        }
    }

    printf("%lld\n", ans%mod);
}

