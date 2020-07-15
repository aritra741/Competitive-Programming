#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    int x,y;
};

int quad( point p )
{
    if(p.x>=0)
    {
        if(p.y>=0)
            return 1;
        return 4;
    }
    else
    {
        if(p.y>=0)
            return 2;
        return 3;
    }
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

bool cmp( const point&a, const point&b )
{
    if(quad( a )!=quad( b ))
        return quad(a)<quad(b);
    point p;
    p.x= 0;
    p.y= 0;
    int pos= area( p, a, b );

    if(pos!=0)
        return pos==2;
    ll dist1= a.x*a.x+a.y*a.y;
    ll dist2= b.x*b.x+b.y*b.y;

    return dist1<dist2;
}

int main()
{
    int n;
    cin>>n;

    point arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i].x>>arr[i].y;

    sort( arr, arr+n, cmp );

    for(int i=0;i<n;i++)
        cout<<arr[i].x<<" "<<arr[i].y<<endl;

}
