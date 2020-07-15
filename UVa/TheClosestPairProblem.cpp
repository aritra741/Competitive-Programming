#include <bits/stdc++.h>
using namespace std;

struct point
{
    double x,y;
} p[10007];

double dist( point a, point b )
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

bool cmp( const point&a, const point&b )
{
    return a.x<b.x;
}

int main()
{
    int n;

    while(scanf("%d", &n)==1 and n)
    {
        for(int i=0; i<n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        sort( p, p+n, cmp );

        double ans= FLT_MAX;

        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                if( p[j].x-p[i].x>ans )
                    break;
                ans= min( ans, dist( p[i],p[j] ) );
            }

        if(ans>=10000)
            printf( "INFINITY\n" );
        else
            printf("%.4f\n", ans);
    }
}
