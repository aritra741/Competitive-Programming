#include <bits/stdc++.h>
using namespace std;

int dp[1010][7010];
bool vis[1010][7010];
int w[1010],cap[1010];
int n;

int rec( int i, int weight )
{
    if( i>=n )
        return 0;
    if( vis[i][weight] )
        return dp[i][weight];

    int q1=0,q2=0;

    if( w[i]<=weight )
        q1= 1+rec(i+1,min(cap[i],weight-w[i]) );
    q2= rec(i+1, weight);

    vis[i][weight]= 1;

    return dp[i][weight]= max(q1, q2);
}

int main()
{
    while(1)
    {
        cin>>n;

        if(!n)
            break;

        for(int i=0; i<n; i++)
            scanf("%d %d", &w[i], &cap[i]);

        printf("%d\n", rec(0, 7001)) ;

        memset(vis,0,sizeof(vis));
    }
}
