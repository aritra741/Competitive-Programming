#include <bits/stdc++.h>
#define ll long long
#define mx 50007
#define pi acos(-1.0)
using namespace std;

struct point
{
    ll x,y;
};

bool operator == (point a, point b)
{
    return (a.x==b.x and a.y==b.y);
}

bool operator < (point a, point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int area( point p, point q, point r )
{
    ll x[]= {p.x, q.x, r.x};
    ll y[]= {p.y, q.y, r.y};

    ll a= 0;
    int j= 2;

    for(int i=0; i<3; i++)
    {
        a+=(x[j]+x[i])*(y[i]-y[j]);
        j= i;
    }

    if(a>0)
        return 1;
    if(a<0)
        return 2;
    return 0;
}

ll dist( point a, point b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double convex_hull( vector<point> p )
{
    int n= p.size();

    if(n==1)
        return 0.00;
    if(n==2)
        return 2.0*sqrt( dist( p[0], p[1] ) );

    vector<point> hull(2*n);

    sort(p.begin(), p.end());

    int k=0;
    for(int i=0; i<n; i++)
    {
        while(k>=2 and area( hull[k-2], hull[k-1], p[i] )!=1)
            k--;
        hull[k++]= p[i];
    }
    for(int i=n-2, t= k+1; i>=0; i--)
    {
        while(k>=t and area( hull[k-2], hull[k-1], p[i] )!=1)
            k--;
        hull[k++]= p[i];
    }

    double per= 0.00;

    if(k==3)
        {
            per= 2.0* sqrt( dist( hull[0], hull[1] ) );
            return per;
        }

    for(int i=0; i<k-1; i++)
        per+= sqrt( dist( hull[i], hull[i+1] ) );

    return per;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        int n,d;
        scanf("%d %d", &n, &d);

        vector<point> points(n);

        for(int i=0; i<n; i++)
            scanf("%lld %lld", &points[i].x, &points[i].y);

        double per= convex_hull( points );

        per+=(2.0*pi*d);

        printf("Case %d: %0.8f\n", t, per);

    }
}
