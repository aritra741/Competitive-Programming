#include <bits/stdc++.h>
#define ll long long
#define sfi(x) scanf("%d", &x)
#define sfl(x) scanf("%lld", &x)
using namespace std;

struct point
{
    ll x,y;
    bool type;
    int g, upor= 0, nich= 0;

    point()
    {

    }

    point( ll a, ll b, bool c )
    {
        x= a;
        y= b;
        type= c;

        g= __gcd( x,y );

        if(g)
            upor= y/g;
        if(g)
            nich= x/g;
    }
} p[200007];

point cent(0,0,0);

int sign( point p, point q, point r )
{
    ll x[]= {p.x, q.x, r.x};
    ll y[]= {p.y, q.y, r.y};

    ll a= 0;
    int j= 2;

    for(int i=0; i<3; i++)
    {
        a+=(x[j]+x[i])*(y[j]-y[i]);
//        a += x[j]*y[i] - x[i] * y[j];
        j= i;
    }

    if(a>0)
        return 1;
    if(a<0)
        return 2;
    return 0;
}

bool cmp( point a, point b )
{
    return sign( cent, a, b )==2;
}

int main()
{
    int tc;
    sfi(tc);

    while(tc--)
    {
        int n;
        sfi(n);

        for( int i=0; i<2*n; i+=2 )
        {
            ll a,b,c,d;
            sfl(a);
            sfl(b);
            sfl(c);
            sfl(d);

            if( llabs(a)<llabs(c) )
                swap( a,c ), swap( b,d );

            p[i]= point( a,b,0 );
            p[i+1]= point( c,d,1 );
        }

        sort( p, p+2*n, cmp );

       for( int i=0;i<2*n;i++ )
            cout<<" "<<p[i].x<<" "<<p[i].y<<endl;

        int ans= 0, cnt= 0, baki= 0, prevup= -2e9, prevnich= -2e9;

        for( int i=0; i<2*n; i++ )
        {
            if( p[i].type==0 )
            {
                if( p[i].upor!=prevup or p[i].nich!=prevnich )
                    ans= max( ans, cnt ), cnt-= baki, baki= 0;
                cnt++;
            }
            else
            {
                if( p[i].upor!=prevup or p[i].nich!=prevnich )
                    ans= max( ans, cnt ), cnt-= baki, baki= 0;
                baki++;
            }

            prevup= p[i].upor;
            prevnich= p[i].nich;

            cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].type<<" "<<cnt<<" "<<ans<<endl;
        }

        ans= max( ans, cnt );

        printf("%d\n", ans);
    }
}
