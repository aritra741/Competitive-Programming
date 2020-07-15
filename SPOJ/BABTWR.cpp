#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100];

struct box
{
    ll l, w, h, area;

    box( int _l, int _w, int _h )
    {
        l= _l;
        w= _w;
        h= _h;

        area= l*w;
    }
};

bool cmp( box &a, box &b )
{
    return a.area<b.area;
}

vector<box> v;

int main()
{
    int n;

    while( scanf("%d", &n)==1 and n )
    {
        for( int i=0;i<n;i++ )
        {
            ll p,q,r;
            scanf("%lld %lld %lld", &p, &q, &r);

            box b1( p,q,r );
            box b2( q,p,r );
            box b3( p,r,q );
            box b4( r,p,q );
            box b5( q,r,p );
            box b6( r,q,p );

            v.push_back( b1 );
            v.push_back( b2 );
            v.push_back( b3 );
            v.push_back( b4 );
            v.push_back( b5 );
            v.push_back( b6 );
        }

        sort( v.begin(), v.end(), cmp );

        for( int i=0;i<v.size();i++ )
            dp[i]= v[i].h;

        for( int j=1;j<v.size();j++ )
            for( int i=0;i<j;i++ )
                dp[j]= ( v[j].l>v[i].l and v[j].w>v[i].w )? max(dp[j], dp[i]+v[j].h):dp[j];

        ll ans= 0;
        for( int i=0;i<v.size();i++ )
            ans= max( ans, dp[i] );

        printf( "%lld\n", ans);

        v.clear();
    }
}
