#include <bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

struct point
{
    ll x,y;
} points[mx], base;

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

bool cmp( const point&a, const point&b )
{
    int pos= area( base, a, b );

    if(pos==0)
        return dist( base, a )> dist(base, b);

    return pos==1;
}

bool cmp2( const point&a, const point&b )
{
    return dist( base, a )< dist(base, b);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int m,n=0;
        scanf("%d", &m);

        for(int i=0; i<m; i++)
        {
            ll p,q;
            char c;
            scanf("%lld %lld %c", &p, &q, &c);

            if(c=='Y')
            {
                points[n].x= p;
                points[n].y= q;
                n++;
            }
        }

        int l= 0;

        for(int i=1; i<n; i++)
            if(points[i].x<points[l].x or ( points[i].x==points[l].x and points[i].y<points[l].y ))
                l= i;
        base= points[l];
        swap( points[l], points[0] );

        sort(points, points+n, cmp);

        int cnt= 1;

        point p,q;
        p.x= 2, p.y= 0;
        q.x= 3, q.y= 0;

        for(int i=0; i<n-1; i++)
        {
            if( area( base, points[i],  points[i+1] )!=0 )
                break;
            cnt++;
        }

        sort( points, points+cnt, cmp2 );

        printf("%d\n%d %d\n", n, points[n-1].x, points[n-1].y);

        for(int i=0; i<n-1; i++)
            printf("%lld %lld\n", points[i].x, points[i].y);

    }
}
/*
7
7
0 0 Y
0 2 Y
3 3 Y
0 3 Y
3 0 Y
3 1 Y
2 0 Y
*/
