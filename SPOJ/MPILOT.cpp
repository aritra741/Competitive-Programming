#include <bits/stdc++.h>
using namespace std;

int dp[5007][5007];
bool vis[5007][5007];
int arr[10007][2];
int n;

int rec( int cnt1, int cnt2 )
{
    int i= cnt1+cnt2;

    if( i>=n )
        return 0;
    if( vis[cnt1][cnt2] )
        return dp[cnt1][cnt2];

    int q1= 2e9, q2= 2e9;

    if( cnt1+1<=n/2 and cnt1<cnt2 )
        q1= arr[i][0]+rec( cnt1+1, cnt2 );
    if( cnt2+1<=n/2 )
        q2= arr[i][1]+rec( cnt1, cnt2+1 );

    vis[cnt1][cnt2]= 1;

    return dp[cnt1][cnt2]= min( q1, q2 );
}

int main()
{
    scanf("%d", &n);

    for( int i=0;i<n;i++ )
        scanf("%d %d", &arr[i][0], &arr[i][1]);

    int ans= rec( 0,0 );

    printf("%d\n", ans);
}
