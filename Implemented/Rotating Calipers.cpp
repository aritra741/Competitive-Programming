#include <bits/stdc++.h>
#define ll long long
#define sf(x) scanf("%lld", &x)
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

struct point
{
    ll x,y;

    point() {}
    point(ll x, ll y) : x(x), y(y) {}
    point(const point &p) : x(p.x), y(p.y)    {}

    point operator - (const point &p)  const
    {
        return point(x-p.x, y-p.y);
    }
};

bool operator < ( const point&a, const point&b )
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

vector<point> points;

ll dist( point p, point q )
{
    return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}

ll cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

int sign( point p, point q, point r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return 1;
    if(val>0)
        return 2;
    return 0;
}

ll max_dist()
{
    int n= points.size();

    if( n==1 )
        return 0;
    if( n==2 )
        return dist( points[0], points[1] );

    vector<point> hull(2*n);

    sort( points.begin(), points.end());

    int k= 0;

    for(int i=0; i<n; i++)
    {
        while(k>=2 and sign(hull[k-2], hull[k-1], points[i])!=2)
            k--;
        hull[k++]= points[i];
    }
    int t= k;
    for(int i=n-2; i>=0; i--)
    {
        while(k>t and sign( hull[k-2], hull[k-1], points[i] )!=2)
            k--;
        hull[k++]= points[i];
    }

    hull.resize(k-1);

    n= hull.size();
    k= 0;
    ll ans= 0;

    for( int i=0; i<n; i++ )
    {
        ans= max(  ans, dist( hull[i], hull[k] ) );
        while( dist( hull[i], hull[(k+1)%n] )>dist( hull[i], hull[k] ) )
            ans= max( ans, dist( hull[i], hull[(k+1)%n] ) ), k= (k+1)%n;
    }

    return ans;
}

int main()
{
    ll tc;
    sf(tc);

    while(tc--)
    {
        ll n;
        sf(n);

        for( int i=0; i<n; i++ )
        {
            point p;
            sf(p.x);
            sf(p.y);

            points.push_back(p);
        }

        ll ans= max_dist();

        printf("%lld\n", ans);

        points.clear();
    }
}

