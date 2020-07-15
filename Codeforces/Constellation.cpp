#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y;
    int idx;
} p[100007];

int sign( point p, point q, point r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return -1;
    if(val>0)
        return 1;
    return 0;
}

bool cmp( point a, point b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>p[i].x>>p[i].y,
            p[i].idx= i+1;

    sort( p, p+n, cmp );

    for(int i=0; i<n-2; i++)
    {
        point a;
        a.x= p[i].x;
        a.y= p[i].y;
        a.idx= p[i].idx;
        point b;
        b.x= p[i+1].x;
        b.y= p[i+1].y;
        b.idx= p[i+1].idx;
        point c;
        c.x= p[i+2].x;
        c.y= p[i+2].y;
        c.idx= p[i+2].idx;

        int pos= sign( a,b,c );

        if(!pos)
            continue;

        bool valid= 1;
        for(int j=i+3; j<n; j++)
        {
            point r;
            r.x= p[j].x;
            r.y= p[j].y;
            r.idx= p[j].idx;

            int val1= sign( a,b,r );
            int val2= sign( b,c,r );
            int val3= sign( c,a,r );

            if( val1*val2<0 or val2*val3<0 or val3*val1<0 );
            else
            {
                valid= 0;
                break;
            }

        }

        if( valid )
        {
            cout<< a.idx <<" "<< b.idx <<" "<< c.idx <<endl;
            break;
        }
    }
}
