#include <bits/stdc++.h>
#define ll long long
#define inf 1500000LL
using namespace std;

struct point
{
    ll x,y,idx;
} p[100007], base;

ll val( point a )
{
    return a.x*a.x+a.y*a.y;
}

int main()
{
    base.x= 0;
    base.y= 0;

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%lld %lld", &p[i].x, &p[i].y),
              p[i].idx= i;

    vector<int> ans(n);
    int cnt= 0;

    do
    {
        cnt++;
        random_shuffle( p, p+n );
        base.x= 0;
        base.y= 0;
        for(int i=0; i<n; i++)
        {
            point P, Q;
            P.x= p[i].x+base.x;
            P.y= p[i].y+base.y;
            Q.x= base.x-p[i].x;
            Q.y= base.x-p[i].y;

            if( val(P)<= val(Q) )
            {
                ans[ p[i].idx ]= 1;
                base.x+= p[i].x;
                base.y+= p[i].y;
            }

            else
            {
                ans[ p[i].idx ]= -1;
                base.x-= p[i].x;
                base.y-= p[i].y;
            }
        }

        if(val(base)<=inf*inf)
            for(int i=0; i<n; i++)
                printf("%d ", ans[i]);

    }
    while( val(base)>inf*inf );

}
