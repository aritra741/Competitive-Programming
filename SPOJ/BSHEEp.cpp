#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll ,ll>
#define plll pair<ll, pll>
using namespace std;

struct point
{
    ll x,y;
};

point first;

int area( point p, point q, point r )
{
    ll x[]= {p.x, q.x, r.x};
    ll y[]= {p.y, q.y, r.y};

    double a= 0.0;
    int j= 2;

    for(int i=0; i<3; i++)
    {
        a+=(x[j]+x[i])*(y[j]-y[i]);
        j= i;
    }

    if(a>0)
        return 1;
    if(a<0)
        return 2;
    return 0;
}

bool cmp1( const point &a, const point&b  )
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

bool cmp2( const point&a, const point&b )
{
    return area( first, a, b )==2;
}

void CHull( point points[], int n )
{
    vector <point> hull;

    int b= 0;

    for(int i=1;i<n;i++)
        if( points[i].y<points[b].y )
            b= i;

    int p= b;
    int cnt= 0;
    do
    {
        hull.push_back( points[p] );

        int q= (p+1)%n;

        for(int i=0;i<n;i++)
        {
            if(q==i or p==i)
                continue;
            int pos= area( points[p], points[q], points[i] );

            if(cnt<10)
            {
                cnt++;
                cout<<p<<" "<<q<<" "<<i<<" "<<pos<<endl;
            }

            if( pos==1 )
                q= i;
            else if( pos==0 )
            {
                ll dist1= ( points[b].x-points[i].x )*( points[b].x-points[i].x )
                         +( points[b].y-points[i].y )*( points[b].y-points[i].y );
                ll dist2 = ( points[b].x-points[q].x )*( points[b].x-points[q].x )
                         +( points[b].y-points[q].y )*( points[b].y-points[q].y );
                if(dist1>dist2)
                    q= i;
            }
        }

        p= q;
    }while(p!=b);

    sort( hull.begin(), hull.end(), cmp1 );
    first= hull[0];
    sort( hull.begin(), hull.end(), cmp2 );

    hull.push_back(first);

    double per= 0.0;

    for(int i=1;i<hull.size();i++)
        per+= sqrt( (hull[i].x-hull[i-1].x)*(hull[i].x-hull[i-1].x)
                   + (hull[i].y-hull[i-1].y)*(hull[i].y-hull[i-1].y) );
     cout<<setprecision(2)<<fixed<<per<<endl;
     for(int i=0;i<hull.size()-1;i++)
        printf("%lld %lld\n", hull[i].x,hull[i].y);
}
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        getchar();
        int n;
        scanf("%d", &n);

        point points[n];

        for(int i=0;i<n;i++)
        {
            point p;
            scanf("%lld %lld", &p.x, &p.y);
            points[i]= p;
        }

        CHull( points, n );

    }
}
