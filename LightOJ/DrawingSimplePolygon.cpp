#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
using namespace std;

struct point
{
    ll x,y,idx;
} base, p[2007];

int sign( point p, point q, point r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val==0)
        return 0;
    if(val<0)
        return 1;
    if(val>0)
        return 2;
}

ll dist( point a, point b )
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp( point a, point b )
{
    int pos= sign( base, a, b );

    if(pos==0)
    {
        ll d1= dist( base, a );
        ll d2= dist( base, b );

        return d1<d2;
    }

    return pos==2;
}


bool cmp1( point a, point b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
bool cmp2( point a, point b )
{
    ll d1= dist( base, a );
    ll d2= dist( base, b );

    return d1<d2;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        cout<<"Case "<<t<<":\n";
        //cout<<"baire\n";
        int n;
        cin>>n;
        int mn= INT_MAX, idx= 0;

        for(int i=0; i<n; i++)
        {
            cin>>p[i].x>>p[i].y;
            p[i].idx= i;
        }

        sort( p, p+n, cmp1 );
        base= p[0];
        sort( p+1, p+n, cmp );

        int cnt= 1;
        int i= n-1;

        while( sign( base, p[i], p[i-1] )==0 and i>0)
            cnt++,i--;

        reverse( p+n-cnt, p+n );

        if(cnt==n)
        {
            cout<<"Impossible\n";
            continue;
        }

        for(int i=0; i<n; i++)
        {
            if(i)
                cout<<" ";
            cout<<p[i].idx;
        }
        cout<<"\n";
    }
}
