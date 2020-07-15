#include <bits/stdc++.h>
using namespace std;

vector <int> adj[10007];
int vis[10007];
pair<int,int> fin[10007];
int t=0;
stack<int> st;


void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        if(vis[adj[x][i]]==0)
                dfs(adj[x][i]);
    }
}


void finTime(int x)
{
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        if(vis[ adj[x][i] ]==0)
            finTime(adj[x][i]);
    }
    st.push(x);
}

int main()
{
    int tc;
    cin>>tc;
    for(int tst=1;tst<=tc;tst++)
    {
        int n,m;
        getchar();
        scanf("%d %d", &n, &m);
        t=0;

        for(int i=0;i<m;i++)
        {
            int p,q;
            scanf("%d %d", &p, &q);
            adj[p].push_back(q);
        }

        memset(vis, 0, sizeof(vis));

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
                finTime(i);
        }

        memset(vis, 0, sizeof(vis));
        int cnt=0;

        while(!st.empty())
        {
            int u=st.top();
            st.pop();
            if(vis[u]==0)
            {
                dfs(u);
                cnt++;
            }
        }
    printf("Case %d: %d\n", tst, cnt);
    for(int i=1;i<=n;i++)
        adj[i].clear();
    }
}

