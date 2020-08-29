#include <bits/stdc++.h>
#define ll long long
#define m 10056
using namespace std;

ll ncr[1007][1007];
ll dp[1007];

void generatencr()
{
    ncr[0][0]=1;

    for(int i=1; i<=1000; i++)
    {
        ncr[i][0]= 1;
        for(int j=1; j<=i; j++)
            ncr[i][j]= (ncr[i-1][j-1]%m+ncr[i-1][j]%m)%m;
    }
}

ll ans( int n )
{
    if( dp[n]!=-1 )
        return dp[n];
    ll cnt= 0;
    for(int i=1; i<=n; i++)
    {
        cnt= (cnt%m + ((ncr[n][i]%m)*(ans(n-i)%m))%m)%m;
    }

    return dp[n]= cnt%m;
}

int main()
{
    generatencr();
    memset(dp, -1, sizeof(dp));
    dp[0]= 1;
    dp[1]= 1;

    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        int n;
        scanf("%d", &n);

        printf("Case %d: %lld\n", t, ans(n));
    }
}
