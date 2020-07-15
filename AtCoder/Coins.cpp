#include<bits/stdc++.h>
#define mx 3007
using namespace std;

double dp[mx][mx];
bool vis[mx][mx];
double p[mx];
int n;

double rec( int i, int x )
{
    if( i>=n )
    {
        if(x>=(n+1)/2)
            return 1.00;
        return 0.00;
    }

    if( vis[i][x] )
        return dp[i][x];

    double ret= 0;

    ret+= p[i]*rec( i+1, x+1 );
    ret+= (1.00-p[i])*rec( i+1, x );

    vis[i][x]= 1;

    return dp[i][x]= ret;
}

int main()
{
    cin>>n;

    for( int i=0;i<n;i++ )
        cin>>p[i];

    cout<<setprecision(12)<<fixed<< rec( 0, 0 ) <<endl;
}
