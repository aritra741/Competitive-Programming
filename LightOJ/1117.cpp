#include<bits/stdc++.h>
#define ll long long
using namespace std;

int arr[20];

ll lcm( ll x, ll y )
{
    return (x/__gcd(x,y))*y;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int n,m;
        scanf("%d %d", &n, &m);

        ll ans= 0;

        for( int i=0;i<m;i++ )
            scanf("%d", &arr[i]);

        for( int x=1;x<=(1<<m)-1;x++ )
        {
            int on= __builtin_popcount(x);
            ll now= 1;

            for( int j=0;j<m;j++ )
                if( (1<<j)&x )
                 now= lcm(now,arr[j]);

            if(!(on&1))
                now*= -1;

            ans+= n/now;
        }

        printf("Case %d: %lld\n", t, n-ans);
    }
}
