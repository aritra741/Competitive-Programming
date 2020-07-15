#include<bits/stdc++.h>
using namespace std;

double dp[107][10];
int vis[107][10];
int n,k,p;

double rec( int i, int last )
{
    if( i>=n )
        return 1.0;
    if( vis[i][last]==p )
        return dp[i][last];

    double ret= 0.0;

    for( int j=0;j<=k;j++ )
    {
        if( i )
        {
            if( abs(j-last)<=1 )
                ret+= rec( i+1, j );
        }
        else
            ret+= rec( i+1, j );
    }

    vis[i][last]= p;

    return dp[i][last]= ret;
}

int main()
{
    while( cin>>k>>n )
    {
        p++;
        double ans= rec( 0, 0 );

        for( int i=1;i<=n;i++ )
            ans/= (k+1);

        cout<<setprecision(5)<<fixed<< ans*100.00 <<endl;
    }
}
