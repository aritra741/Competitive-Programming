#include<bits/stdc++.h>
#define eps 1e-7
using namespace std;

int n,p;
double dp[107];
int vis[107];
int arr[107];
double pre[10007];
double r,v,e,f,b;

double rec( int i )
{
    if( i==n )
        return 0.0;
    if( vis[i]==p )
        return dp[i];

    double ret= 1e18;

    for( int j=i+1; j<=n; j++ )
    {
        ret= min( ret, b+pre[arr[j]-arr[i]]+rec( j ) );
    }

//    ret= min( ret, pre[arr[n]-arr[i]]+b );

    vis[i]= p;

    return dp[i]= ret;
}

int main()
{
    while( scanf("%d", &n)==1 and n )
    {
        for( int i=1; i<=n; i++ )
            scanf("%d", &arr[i]);
        scanf("%lf", &b);
        scanf("%lf %lf %lf %lf", &r, &v, &e, &f);

        int i=1;
        for( double x=0.0; x<=10000.00; x= x+1.0, i++ )
        {
            double now;
            if( x>=r )
                now= 1.00/( v-e*(x-r) );
            else
                now= 1.00/( v-f*(r-x) );

            pre[i]= pre[i-1]+now;
        }

//        cout<<b+pre[2]+<<endl;

        p++;

        double ans= 1e18;

        for( int i=1; i<=n; i++ )
            ans= min( ans, pre[ arr[i] ]+ rec( i ) );

        printf("%.4f\n", ans );
    }
}
