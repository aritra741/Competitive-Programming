#include <bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

struct point
{
    int x,y;
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
        return 1;
    else if(val<0)
        return 2;
    return 0;
}

vector<point> convex_hull( vector<point> p )
{
    set<point> st;
    set<point> ::iterator it;

    int n= p.size();

    for(int i=0; i<n; i++)
        st.insert( p[i] );

    int i=0;

    p.clear();

    for(it=st.begin(); it!=st.end(); it++)
    {
        p.push_back( (*it) );
    }

    n= p.size();
    vector<point> hull(2*n);
    vector<point> emp;
    if(st.size()<3)
        return emp;

    sort(p.begin(), p.begin()+n);

    int k=0;
    for(int i=0; i<n; i++)
    {
        while(k>=2 and sign( hull[k-2], hull[k-1], p[i] )!=1 )
            k--;
        hull[k++]= p[i];
    }

    int t= k;
    for(int i=n-2; i>=0; i--)
    {
        while(k>t and sign( hull[k-2], hull[k-1], p[i] )!=1)
            k--;
        hull[k++]= p[i];
    }

    hull.resize(k-1);
    return hull;

}

ll area( point p, point q, point r )
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

    return abs(a);
}

ll dist( point a, point b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double getDist( point a, point b, point c)
{
    ll A= area( a,b,c );
    double ab= sqrt((double)dist( a,b ));

    double h= (double)A/(double)ab;

    return h;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n;
        cin>>n;

        vector<point> points(n);

        for(int i=0; i<n; i++)
            cin>>points[i].x>>points[i].y;

        vector<point> hull= convex_hull(points);

        if(hull.size()==0)
        {
            cout<<"Case #"<<t<<": 0.000\n";
            continue;
        }

        hull.push_back(hull[0]);
        int sz= hull.size();
        int sz2= points.size();
        double ans= 1000000000.00;
        ///
//        cout<<endl;
//        for(int i=0;i<sz;i++)
//            cout<<hull[i].x<<" "<<hull[i].y<<endl;
//        cout<<endl;
        ///
        for(int i=0; i<sz-1; i++)
        {
            double ave= 0.0;
            for(int j=0; j<sz2; j++)
                ave+= getDist( hull[i], hull[i+1], points[j] );
            ave/=(double)sz2;
            ans= min( ans, ave );
           // cout<<ans<<endl;
        }

        cout<<"Case #"<<t<<": "<<setprecision(3)<<fixed<<ans<<endl;

    }
}



