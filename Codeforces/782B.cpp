#include<bits/stdc++.h>
using namespace std;

int n;
double arr[60007], v[60007];

double Min( double x, double y )
{
    if( x<y )
        return x;
    return y;
}

double Max( double x, double y )
{
    if( x>y )
        return x;
    return y;
}

bool chk( double t )
{
    double l= -1e18, r= 1e18;

    for( int i=0;i<n;i++ )
        l= Max( l, arr[i]-v[i]*t ), r= Min( r, arr[i]+v[i]*t );
    return l<=r; /// checking whether all [ x[i]-v[i]*t, x[i]+v[i]*t ] intersect
}

int main()
{
    scanf("%d", &n);

    double mx= 0;

    for( int i=0;i<n;i++ )
        scanf("%lf", &arr[i]), mx= Max(mx,arr[i]);
    for( int i=0;i<n;i++ )
        scanf("%lf", &v[i]);

    double low= 0.0, high= 1e18;
    double ans= 1e18;

    for( int i=0;i<100;i++ )
    {
        double mid= ( high+low )/2.0;

        if( chk(mid) )
            ans= mid, high= mid;
        else
            low= mid;
    }

    printf("%.10f\n", ans);
}
