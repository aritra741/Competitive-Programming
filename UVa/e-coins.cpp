#include <bits/stdc++.h>
#define eps 1e-7
#define ll long long
#define inf INT_MAX
using namespace std;

ll dp[310][310];
bool vis[310][310];
int c[310], in[310];
int n, target;

ll rec( int conv, int info )
{
    double x= conv;
    double y= info;
    double val= sqrt( x*x+y*y );

    if( val-target>eps )
        return inf;
    if( fabs(val-target)<= eps)
            return 0;
    if( vis[conv][info] )
        return dp[conv][info];

    ll ans= inf;

    for(int i=0;i<n;i++)
        ans= min( ans, 1+rec( conv+c[i], info+in[i] ) );

    vis[conv][info]= 1;

    return dp[conv][info]= ans;

}


int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n>>target;

        for(int i=0;i<n;i++)
            cin>>c[i]>>in[i];

        ll ans= rec( 0, 0 );

        if(ans>=inf)
            cout<<"not possible\n";
        else
            cout<< ans <<endl;

        memset( vis, 0, sizeof(vis) );
    }
}
