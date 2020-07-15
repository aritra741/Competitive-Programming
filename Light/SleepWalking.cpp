#include <bits/stdc++.h>
#define ll long long
#define X 10050
#define Y 10050
using namespace std;

bool vertex;

struct point
{
    ll x,y;
} p[200];

ll dist( point a, point b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int area( point p, point q, point r )
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

    if(a>0)
        return 1;
    if(a<0)
        return 2;
    return 0;
}

bool intersect( point p, point q, point r, point s )
{
    if( sqrt(dist(q,r))+ sqrt(dist(q,s)) == sqrt(dist(r,s)) )
    {
        vertex= 1;
        return 1;
    }

    int pos1= area( p,q,r );
    int pos2= area( p,q,s );
    int pos3= area( r,s,p );
    int pos4= area( r,s,q );

    if(pos1!=pos2 and pos3!=pos4)
        return 1;
    return 0;
}

bool operator == (point a, point b)
{
    return a.x==b.x and a.y==b.y;
}

void what()
{
    point arr[4];

    for(int i=0;i<4;i++)
        cin>>arr[i].x>>arr[i].y;

    cout<<intersect(arr[2], arr[3], arr[0], arr[1])<<endl;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        printf("Case %d:\n", t);
        int n;
        scanf("%d", &n);

        for(int i=0; i<n; i++)
            scanf("%lld %lld", &p[i].x, &p[i].y);

        p[n]= p[0];

        int q;
        scanf("%d", &q);

        while(q--)
        {
            vertex= 0;
            point pt;
            scanf("%lld %lld", &pt.x, &pt.y);

            int odd= 0, even= 0;

            for(int i=0; i<=10 and !vertex; i++)
            {
                point cast;
                cast.x= X+i;
                cast.y= Y-i;

                int cnt= 0;
                for(int j=0; j<n; j++)
                {
                    if( p[j]==pt )
                    {
                        vertex=1;
                        break;
                    }

                    if( intersect( cast, pt, p[j], p[j+1] ) )
                        cnt++;
                }

                if(cnt&1)
                    odd++;
                else
                    even++;
            }

            if(odd>even or vertex)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}
