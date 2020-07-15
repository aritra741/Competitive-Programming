#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool dp[10007][1007];
bool vis[10007][1007];
int n,k;
ll arr[10007];

bool rec( int i, ll tot  )
{
    if(i>=n)
    {
        if(tot%k==0)
            return 1;
        return 0;
    }

    if(vis[i][tot])
        return dp[i][tot];

    bool q1= rec( i+1, (tot+arr[i])%k );
    bool q2= rec( i+1, (tot-arr[i])%k );

    vis[i][tot]= 1;

    return dp[i][tot]= q1 or q2;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        scanf("%d %d", &n, &k);

        for(int i=0;i<n;i++)
            scanf("%lld", &arr[i]);

        bool poss= rec(0,0);

        if(poss)
            printf("Divisible\n");
        else
            printf("Not divisible\n");

        memset(vis,0,sizeof(vis));
    }
}

