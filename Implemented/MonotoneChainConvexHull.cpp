#include <bits/stdc++.h>
#define mx 10007
#define ll long long
using namespace std;

struct point
{
    ll x,y;
};

bool operator == (point a, point b)
{
    return a.x==b.x and a.y==b.y;
}

vector<point> points(mx);

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

bool operator < ( const point&a, const point&b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

vector<point> convex_hull( vector<point> points )
{
    int n= points.size();
    vector<point> hull(2*n);
    sort( points.begin(), points.end());

    int j= 0;

    for(int i=0; i<n; i++)
    {
        while(j>=2 and area( hull[j-2], hull[j-1], points[i] )!=1)
            j--;
        hull[j++]= points[i];
    }
    for(int i=n-2, t=j+1; i>=0; i--)
    {
        while(j>=t and area( hull[j-2], hull[j-1], points[i] )!=1 )
            j--;
        hull[j++]= points[i];
    }
    hull.resize(j-1);

    return hull;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        set<point> st;
        set<point> ::iterator it;

        for(int i=0;i<n;i++)
        {
            point p;
            cin>>p.x>>p.y;
            st.insert(p);
        }

        n= 0;
        for(it=st.begin();it!=st.end();it++)
        {
            points[n].x= (*it).x;
            points[n++].y= (*it).y;
        }

        vector<point> h= convex_hull(points);

        for(int i=0;i<h.size();i++)
            cout<<h[i].x<<" "<<h[i].y<<endl;
    }
}
