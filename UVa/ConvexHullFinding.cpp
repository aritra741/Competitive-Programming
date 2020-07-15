#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y;
};

point base;

bool operator == (point a, point b)
{
    return (a.x == b.x && a.y == b.y);
}

bool operator < (point a, point b)
{
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}
int area( point p, point q, point r )
{
    ll x[]= {p.x, q.x, r.x};
    ll y[]= {p.y, q.y, r.y};

    ll a= 0;
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

bool cmp1( const point&a, const point&b  )
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

bool cmp2( const point&a, const point&b )
{
    if( area( base, a, b )==2 )
        return 1;
    return 0;
}


void cHull( point points[], int n )
{
    set<point> hull;
    vector <point> col;
    set<point> ::iterator it;
    int l= 0;

    for(int i=1; i<n; i++)
        if(points[i].y<points[l].y)
            l= i;

    int p=l, q;

    do
    {
        hull.insert( points[p] );

        q= (p+1)%n;

        for(int i=0; i<n; i++)
        {
            if(i==q or i==p)
                continue;
            int pos= area( points[p], points[q], points[i] );
            if( pos==2 )
                q= i;
            else if(pos==0)
            {
                ll dist1= (points[p].x-points[i].x)*(points[p].x-points[i].x)
                          +(points[p].y-points[i].y)*(points[p].y-points[i].y);
                ll dist2= (points[p].x-points[q].x)*(points[p].x-points[q].x)
                          +(points[p].y-points[q].y)*(points[p].y-points[q].y);

                if(dist1>dist2)
                    q= i;
            }
        }

        p= q;

        for(int i=0; i<col.size(); i++)
            hull.insert( col[i] );
    }
    while(points[p].x!=points[l].x or points[p].y!=points[l].y);

    vector <point> cHull;

    for(it=hull.begin(); it!=hull.end(); it++)
        cHull.push_back( *it );

    sort( cHull.begin(), cHull.end(), cmp1 );
    base= cHull[0];
    sort( cHull.begin()+1, cHull.end(), cmp2 );

    int sz= cHull.size();



    int cnt= 0;
    for(int i=0; i<sz; i++)
    {
        if(cHull[i].x==base.x and cHull[i].y==base.y)
            continue;
        cnt++;
    }

    while(cHull.size()<3)
        cHull.push_back(base);


    cout<<max(cnt+2, 3)<<endl;
    cout<<base.x<<" "<<base.y<<endl;

    int k=0;
    sz= hull.size();

    for(int i=0; i<sz; i++)
    {
        //cout<<k<<endl;
        if(cHull[i].x==base.x and cHull[i].y==base.y)
        {
            k++;
            if(k<=2)
                continue;
        }
        cout<<cHull[i].x<<" "<<cHull[i].y<<endl;
    }
    cout<<base.x<<" "<<base.y<<endl;
}

int main()
{
    int tc;
    cin>>tc;
    cout<<tc<<endl;
    for(int t=1; t<=tc; t++)
    {
        int n;
        cin>>n;
        point points[n];

        for(int i=0; i<n; i++)
        {
            point p;
            cin>>p.x>>p.y;
            points[i]= p;
        }

        int l;
        if(t!=tc)
            cin>>l;

        cHull(points, n);

        if(t!=tc)
            cout<<l<<endl;
    }
}
