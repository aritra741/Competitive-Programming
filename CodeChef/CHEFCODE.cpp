#include<bits/stdc++.h>
#define mx 1000000000000000000LL
#define ll long long
using namespace std;

ll arr[35], sub[35];
ll xx[32770], yy[32770];

int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);

    for( int i=0; i<n; i++ )
        scanf("%lld", &arr[i]);

    int sizex= n/2;
    int sizey= n-sizex;

    int ans= 0;

    for( int i=1; i<(1<<sizex); i++ )
    {
        ll prod= 1LL;
        bool f= 0;

        for( int j=0; j<sizex; j++ )
        {
            if( i&(1<<j) )
            {
                ll rem= mx/prod;
                if( arr[j]>rem )
                    f= 1;
                else
                    prod*= arr[j];
            }
        }

        if(!f)
            xx[i-1]= prod;
        else
            xx[i-1]= 2e18;

        if( xx[i-1]<=k )
            ans++;
    }

    for( int i=1; i<(1<<sizey); i++ )
    {
        bool f= 0;
        ll prod= 1ULL;

        for( int j=0; j<sizey; j++ )
            if( i&(1<<j) )
            {
                ll rem= mx/prod;
                if( arr[j+sizex]>rem )
                    f= 1;
                else
                    prod*= arr[j+sizex];
            }

        if(!f)
            yy[i-1]= prod;
        else
            yy[i-1]= 2e18;

        if( yy[i-1]<=k )
            ans++;
    }

    sort( yy, yy+sizey );

    for( int i=0; i<(1<<sizex)-1; i++ )
    {
        ll p= xx[i];
        int now= upper_bound( yy, yy+sizey, k/p )-yy;

        ans+= now;
    }

    printf("%d\n", ans);
}
