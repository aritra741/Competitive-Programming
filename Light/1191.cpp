#include<bits/stdc++.h>
using namespace std;

int n,k,m,pp;

int dp[55][55];
int vis[55][55];

int rec( int i, int s )
{
    if(i>=k)
    {
        if(!s)
            return 1;
        return 0;
    }

    if(vis[i][s]==pp)
        return dp[i][s];

    int ret= 0;
    for( int x=1;x<=m;x++ )
    {
        if(s-x>=0)
            ret+= rec(i+1,s-x);
        else
            break;
    }

    vis[i][s]= pp;

    return dp[i][s]= ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        pp++;
        scanf("%d %d %d", &n, &k, &m);

        int ans= rec(0,n);

        printf("Case %d: %d\n", t, ans);
    }
}
