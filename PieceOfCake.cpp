#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y;
} base;

vector<point> ret(5007), p;

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

ll dist( point a, point b )
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp( point a, point b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    int n,k;
    cin>>n>>k;

    for( int i=0;i<n;i++ )
    {

    }
}
