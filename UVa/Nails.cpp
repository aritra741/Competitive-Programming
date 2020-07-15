#include <bits/stdc++.h>
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

bool operator < (point a, point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int sign( point p, point q, point r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);
    if(val>0)
        return 2;
    if(val<0)
        return 1;
    return 0;
}

double getdist( point a, point b )
{
    return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

double convex_hull( vector<point> p )
{
    int n= p.size();
    sort( p.begin(), p.end() );
    vector<point> hull(2*n);
    int k= 0;

    for(int i=0;i<n;i++)
    {
        while( k>=2 and sign( hull[k-2], hull[k-1], p[i] )!=2 )
            k--;
        hull[k++]= p[i];
    }

    int t= k;

    for(int i=n-2;i>=0;i--)
    {
        while( k>t and sign(hull[k-2], hull[k-1], p[i])!=2 )
            k--;
        hull[k++]= p[i];
    }

    hull.resize(k-1);
    hull.push_back(hull[0]);

    double area= 0.0;

    for(int i=0;i<k-1;i++)
        area+= getdist( hull[i], hull[i+1] );

    return area;
}



int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        double len;
        int nails;
        cin>>len>>nails;

        vector<point> p(nails);

        for(int i=0;i<nails;i++)
            cin>>p[i].x>>p[i].y;

        if(nails==1)
        {
            cout<<setprecision(5)<<fixed<<len<<endl;
            continue;
        }

        else if(nails==2)
        {
            cout<<setprecision(5)<<fixed<<max(getdist(p[0],p[1])*2.0, len)<<endl;
            continue;
        }

        double ans= convex_hull( p );

        cout<<setprecision(5)<<fixed<< max(ans,len) << endl;
    }
}
