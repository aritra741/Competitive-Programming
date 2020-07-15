#include<bits/stdc++.h>
using namespace std;

int n,p;
int dp[107][107];
int vis[107][107];
int arr[107], b[107], t[107];

int rec( int i, int agey )
{
    if(i>=n)
        return 0;
    if( vis[i][agey]==p )
        return dp[i][agey];

    int ret= t[i]+rec( i+1, min(n,agey+b[i]) );
    if( agey )
        ret= min( ret, t[i]/2+rec( i+1, min(n,agey+b[i]-1) ) );

    vis[i][agey]= p;

    return dp[i][agey]= ret;
}

int main()
{
    while( scanf("%d", &n)==1 and n )
    {
        for( int i=0;i<n;i++ )
            scanf("%d %d", &t[i], &b[i]);

        p++;

        printf("%d\n", rec( 0, 0 ));
    }
}
