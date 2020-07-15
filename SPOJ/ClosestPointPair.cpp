#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y,idx;
} p[50007];

bool cmp( const point&a, const point&b )
{
    return a.x<b.x;
}

double dist( point a, point b )
{
    return sqrt( (a.x-b.x)*(a.x-b.x)+( a.y-b.y) *(a.y-b.y) ) ;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%lld %lld", &p[i].x, &p[i].y);
        p[i].idx= (ll)i;
    }

    sort( p,p+n,cmp );

    double ans= FLT_MAX;
    ll idx1= 0, idx2= 1;

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            if( p[j].x-p[i].x>ans )
                break;
            double d= dist( p[i], p[j] );
            if( d<ans )
                ans= d, idx1= p[i].idx, idx2= p[j].idx;
        }

    printf("%lld %lld %0.6f\n", min(idx1,idx2), max(idx1,idx2), ans);
}

