#include<bits/stdc++.h>
using namespace std;

double dp[65540];
int vis[65540];
double x[17], y[17];
int n,p;

double dist( double x1, double x2, double y1, double y2 )
{
    return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
}

double rec( int mask )
{
    if( __builtin_popcount(mask)==n )
        return 0.0;
    if( vis[mask]==p )
        return dp[mask];

    double ret= 1e18;
    for( int i=0;i<n;i++ )
    {
        if( mask&(1<<i) )
            continue;
        for( int j=i+1;j<n;j++ )
        {
            if( mask&(1<<j) )
                continue;

            double dd= dist( x[i], x[j], y[i], y[j] );

            int now= mask|(1<<i);
            now= now|(1<<j);

            ret= min( ret, dd+rec( now ) );
        }
    }

    vis[mask]= p;

    return dp[mask]= ret;
}

int main()
{
    int tc= 1;
    while( scanf("%d", &n)==1 and n )
    {
        p++;
        n*= 2;

        char s[22];

        for( int i=0;i<n;i++ )
            scanf("%s %lf %lf", s, &x[i], &y[i]);

        printf("Case %d: %.2f\n", tc++, rec(0) );
    }
}
