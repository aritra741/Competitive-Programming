#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[2005][2005],val[2005],w[2005];
bool vis[2005][2005];
int n,cap;

ll knpsck(int i, ll weight)
{
    if(i>n)
        return 0;
    if(vis[i][weight])
        return dp[i][weight];

    int p1,p2;

    if(w[i-1]+weight<=cap)
        p1= val[i-1]+knpsck(i+1, w[i-1]+weight);
    else
        p1=0;
    p2= knpsck(i+1, weight);

    vis[i][weight]=1;
    return dp[i][weight]= max(p1, p2);
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d", &cap, &n);

        for(int i=0;i<n;i++)
        {
            ll c,p;
            scanf("%lld %lld", &c, &p);
            w[i]=c;
            val[i]=p;
        }

        printf("%lld\n", knpsck(1,0));

        memset(vis, 0, sizeof(vis));
    }
}
