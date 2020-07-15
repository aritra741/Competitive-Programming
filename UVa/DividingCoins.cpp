#include <bits/stdc++.h>
#define MX 50010
using namespace std;

int n, cap;
int dp[110][MX];
bool vis[110][MX];
int val[MX];

int knpsck(int i, int curr)
{
    if(i>n)
        return 0;
    if(vis[i][curr])
        return dp[i][curr];

    int p1,p2;

    if(val[i-1]+curr<=cap)
        p1= val[i-1]+knpsck(i+1, curr+val[i-1]);
    else
        p1=0;
    p2= knpsck(i+1, curr);

    vis[i][curr]=1;

    return dp[i][curr]=max(p1,p2);

}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d", &n);

        for(int i=0;i<n;i++)
        {
            scanf("%d", &val[i]);
            cap+=val[i];
        }

        int tot=cap;
        cap= ceil( (double)cap/2.0 );

        int ans= knpsck(1,0);

        printf("%d\n", abs(tot-ans-ans));

        cap=0;
        memset(vis, 0, sizeof(vis));
    }
}
