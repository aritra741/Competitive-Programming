#include <bits/stdc++.h>
#define mx 100007
#define ll long long
#define eps 1e-7
#define pi 3.14159265358979323846

using namespace std;

struct point
{
    ll x,y;
}base, points[mx], hull[mx];

int Size;

int area( point p, point q, point r )
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

ll dist( point a, point b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp1( const point&a, const point&b )
{
    int pos= area( base, a, b );

    if(pos==0)
    {
        ll d1= dist( base, a );
        ll d2= dist( base, b );

        return d1>d2;
    }

    return pos==2;
}

bool cmp2( const point&a, const point&b )
{
    ll d1= dist( base, a );
    ll d2= dist( base, b );

    return d1<d2;
}

void Hull( int n )
{
    int l= 0;

    for( int i=1;i<n;i++ )
        if( points[i].x<points[l].x or ( points[l].x==points[i].x and points[l].y>points[i].y) )
            l= i;

    swap( points[0], points[l] );
    base= points[0];

    sort( points+1, points+n, cmp1 );

    int cnt= 1;

    for(int i=1;i<n-1;i++)
    {
        if( area( base, points[i], points[i+1] )!=0 )
            break;
        cnt++;
    }

    sort( points, points+cnt, cmp2 );

    int m=1;

    for(int i=1;i<n;i++)
    {
        while( i<n-1 and area(base, points[i], points[i+1])==0 )
            i++;
        points[m++]= points[i];
    }

    if(m<3)
    {
        Size=m;
        return;
    }

    for(int i=0;i<3;i++)
        hull[i]= points[i];

    int j=3;

    for(int i=3;i<n;i++)
    {
        while( area( hull[j-2], hull[j-1], points[i] )!=2 )
            j--;
        hull[j++]=points[i];
    }

    Size= j;
}

double radtodeg( double rad )
{
    return (rad*180.00)/pi;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n;
        scanf("%d", &n);
        set<pair<ll, ll> > st;
        set<pair<ll, ll> > :: iterator it;
        for(int i=0;i<n;i++){
            scanf("%lld %lld", &points[i].x, &points[i].y);
            st.insert({points[i].x, points[i].y});
        }
        n = 0;

        for(it = st.begin(); it != st.end(); it++)
        {
            points[n].x = it->first;
            points[n++].y = it->second;
        }


        if(n<3)
        {
            printf("Case %d: 0\n", t);
            continue;
        }

        Hull(n);

        if(Size<3)
        {
            printf("Case %d: 0\n", t);
            continue;
        }

        hull[Size]= hull[0];
        hull[Size+1]= hull[1];

        double angle= 180.00;

        for(int i=1;i<=Size;i++)
        {
            double diag= sqrt( dist( hull[i+1], hull[i-1] ) );
            double d1= sqrt( dist( hull[i+1], hull[i] ) );
            double d2= sqrt( dist( hull[i-1], hull[i] ) );
            double theta;

            if(2*d1*d2==0)
                theta= 0.00;
            else
                theta= acos( (d1*d1+d2*d2-diag*diag)/(2.00*d1*d2) );
            theta= radtodeg(theta);

            angle= min( angle, theta );
        }

        if(angle>=180.00)
            angle= 0.00;

        cout<<"Case "<<t<<": "<<setprecision(6)<<fixed<<angle<<endl;
    }
}
