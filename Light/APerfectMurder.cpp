#include <bits/stdc++.h>
#define mx 1007
using namespace std;

vector<int> adj[mx];
bool vis[mx];
int dp1[mx],dp2[mx];    /// dp1= including this node, dp2= max of including and not including the child

void dfs( int u )
{
    vis[u]= 1;
    int sz= adj[u].size();
    int sum1= 0, sum2= 0;

    for(int i=0; i<sz; i++)
    {
        int v= adj[u][i];

        if(!vis[v])
        {
            dfs(v);
            sum1+= dp2[v];
            sum2+= max( dp1[v], dp2[v] );
        }
    }

    dp1[u]= sum1+1;
    dp2[u]= sum2 ;
}
int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        int n,m;
        scanf("%d %d", &n, &m);

        for(int i=0; i<m; i++)
        {
            int p,q;
            scanf("%d %d", &p, &q);
            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        int ans= 0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
                continue;
            dfs(i);
            ans+= max( dp1[i],dp2[i] );
        }

        printf("Case %d: %d\n", t, ans);

        for(int i=1;i<=n;i++)
            adj[i].clear();

        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        memset(vis,0,sizeof(vis));
    }
}
