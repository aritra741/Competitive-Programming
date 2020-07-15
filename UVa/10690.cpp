#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

int arr[101];
pii dp[101][55][2500][2];
int vis[101][55][2500][2];
int tot, n, m, p;

pii rec( int i, int x, int sum, bool neg )
{
    if( x==n )
    {
        int ashol= sum;

        if( neg )
            ashol*= -1;

        return pii(ashol*(tot-ashol),ashol*(tot-ashol));
    }
    if( i>=n+m )
        return pii(-2e9,2e9);

    if( vis[i][x][sum][neg]==p )
        return dp[i][x][sum][neg];

    pii ret= rec( i+1, x, sum, neg );

    int ashol= sum;
    if( neg )
        ashol*= -1;

    bool now= (arr[i]+ashol<0)?1:0;

    pii ret2= rec( i+1, x+1, abs(ashol+arr[i]), now );

    vis[i][x][sum][neg]= p;

    dp[i][x][sum][neg].f= max( ret.f, ret2.f ),
    dp[i][x][sum][neg].s= min( ret.s, ret2.s );

    return dp[i][x][sum][neg];
}

int main()
{
    while( scanf("%d %d", &n, &m)==2 )
    {
        p++;
        tot= 0;
        for( int i=0;i<n+m;i++ )
            scanf("%d", &arr[i]), tot+= arr[i];

        pii ans= rec( 0, 0, 0, 0 );

        printf("%d %d\n", ans.f, ans.s);
    }
}
