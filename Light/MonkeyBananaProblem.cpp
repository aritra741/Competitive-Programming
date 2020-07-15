#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define inf INT_MAX
using namespace std;

ll arr[310][310], dp[310][310];
int vis[310][310];
int n, p;

ll rec( int i, int j )
{
    if(i>2*n-2 or j<0 or j>2*n-2)
        return 0;

    if( vis[i][j]==p )
        return dp[i][j];

    ll p1=  arr[i][j] + rec( i+1, j );
    ll p2= 0, p3= 0;

    if(i<n-1)
        p2= arr[i][j] + rec( i+1, j+1 );
    else
        p3= arr[i][j]+rec( i+1, j-1 );

    vis[i][j]= p;

    return dp[i][j]= max( p1, max( p2, p3 ) );


}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        p++;
        scanf("%d", &n);

        for(int i=0; i<n; i++)
            for(int j=0; j<=i; j++)
                scanf("%d",&arr[i][j]);

        for(int i=n ; i < 2*n-1; i++)
            for(int j= 0; j<2*n-1-i; j++)
                scanf("%d",&arr[i][j]);


        printf("Case %d: %lld\n", t, rec( 0, 0));

        for(int i=0;i<=2*n-1;i++)
            for(int j=0;j<=2*n-1;j++)
                arr[i][j]= 0;
    }
}
