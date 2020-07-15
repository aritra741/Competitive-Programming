#include <bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

struct point
{
    ll x,y;
}points[mx];

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

bool inside( int n, point p )
{
    int low= 1, high= n-1, mid;

    while(high-low>1)
    {
        mid= (low+high)>>1;

        int pos= area( points[0], points[mid], p );

        if(pos==2)
            low= mid;
        else
            high= mid;
    }

    if( area( points[0], points[low], p )==1 )
        return false;
    if( area( points[low], points[high], p )==1 )
        return false;
    if( area( points[high], points[0], p )==1 )
        return false;
    return true;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t=1;t<=tc;t++)
    {
       // getchar();
       // printf("Case %d:\n", t);

        int n;
        scanf("%d", &n);

        for(int i=0;i<n;i++)
            scanf("%lld %lld", &points[i].x, &points[i].y);

        int q;
        scanf("%d", &q);

        while(q--)
        {
            point p;
            scanf("%lld %lld", &p.x, &p.y);

            if( inside( n, p ) )
                printf("y\n");
            else
                printf("n\n");
        }

    }
}
