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

ll area( point p, point q, point r )
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

    return llabs(a);
}

ll cross( point a, point b, point c )
{
    return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

void bord()
{
    int k=0, n= p.size();
    sort(p.begin(),p.end(),cmp);

    for(int i=0; i<n; i++)
    {
        while(k>=2 and sign(ret[k-2], ret[k-1], p[i])!=2)
            k--;
        ret[k++]= p[i];
    }
    int t= k;
    for(int i=n-2; i>=0; i--)
    {
        while(k>t and sign( ret[k-2], ret[k-1], p[i] )!=2)
            k--;
        ret[k++]= p[i];
    }

    ret.resize(k-1);
}


int main()
{
    int n;
    scanf("%d", &n);

    for( int i=0; i<n; i++ )
    {
        point pp;
        scanf("%lld %lld", &pp.x, &pp.y);

        p.push_back( pp );
    }

    bord();

    ll ans= 0;

    ll last= 0;

    n= ret.size();

    for( int i=0; i<n; i++ )
    {
        int k= (i+1)%n;

        for( int j= i+1; j<n; j++ )
        {
            ll last= 0;
            while( (k+1)%n!=i and area(ret[i], ret[j], ret[k])<=area( ret[i], ret[j], ret[(k+1)%n] ) )
                    k= (k+1)%n;
            ans= max( ans, area(ret[i], ret[j], ret[k]) );
        }
}

if(ans&1)
    printf("%lld.5000000\n", ans/2);
else
    printf("%lld.0000000\n", ans/2);
}

/*
7
0 0
0 5
7 7
0 10
0 0
20 0
10 10
*/
