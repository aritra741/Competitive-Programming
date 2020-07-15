#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y;

    point(){x = y = 0; }
    point(ll _x, ll _y) {x = _x, y = _y; }

    point operator-(const point &a) const{
        return point(x - a.x, y - a.y);
    }
};

ll dist( point a, point b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

ll cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

bool cmp ( point a, point b )
{
    if( a.x==b.x )
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int l,w;
        scanf("%d %d", &l, &w);

        int n;
        scanf("%d", &n);

        point arr[n+5];
        ll y[n+5];
        y[0]= 0;
        y[n+1]= w;

        for( int i=0;i<n;i++ )
            scanf("%lld %lld", &arr[i].x, &arr[i].y), y[i+1]= arr[i].y;

        sort( arr, arr+n, cmp );
        sort( y, y+n+2 );

        ll ans= 0.0;
        bool ok= 0;

        for( int i=0;i<=n+1;i++ )
            for( int j=i+1;j<=n+1;j++ )
            {
                ll boty= y[i];
                ll topy= y[j];
                ll leftx= 0;
                ll rightx= l;

                for( int k=0;k<n;k++ )
                {
                    if( arr[k].y>boty and arr[k].y<topy and arr[k].x>leftx and arr[k].x<rightx )
                    {
                        cout<<topy<<" "<<boty<<endl;
                        ok= 1;
                        point p( leftx-arr[k].x, 0 );
                        point q( 0, topy-boty );

                        ll rect=llabs(cross( p,q ));

                        ans= max( ans, rect );

                        leftx= arr[k].x;
                    }
                }
            }

            if(!ok)
                ans= l*w;

            printf("Case %d: %lld\n", t, ans);

    }
}
