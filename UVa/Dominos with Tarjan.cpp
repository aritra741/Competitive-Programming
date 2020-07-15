/* The key Idea here is that every SCC with 0 indegree will contribute to the answer */

#include <bits/stdc++.h>
#define MX 100007
using namespace std;

bool vis[MX];
int low[MX],d[MX],par[MX], bel[MX], ind[MX];
vector <int> adj[MX];
stack <int> st;
int Time;
int scc;

void initialize()
{
    for(int i=0;i<MX;i++)
        par[i]=bel[i]=-1;
    Time=0;
    scc=0;
}

void clean(int n)
{
    for(int i=0;i<=n;i++)
    {
        par[i]=bel[i]=-1;
        low[i]=d[i]=vis[i]=ind[i]=0;
        adj[i].clear();
    }
    Time=0;
    scc=0;
    st=stack<int>();
}

void tarjan(int u)
{
    vis[u]=1;
    low[u]=d[u]=++Time;
    st.push(u);

    int sz=adj[u].size();

    for(int i=0;i<sz;i++)
    {
        int v=adj[u][i];

        if(!vis[v])
        {
            tarjan(v);

            low[u]= min(low[u], low[v]);
        }

        else if(bel[v]==-1)
            low[u]=min(low[u], d[v]);
    }

    if(low[u]==d[u])
    {
        while(st.top()!=u)
        {
            int t=st.top();
            st.pop();
            bel[t]=scc;
        }
        if(st.top()==u)
            st.pop();
        bel[u]=scc;
        scc++;
    }
}

void dfs(int u)
{
    vis[u]=1;

    int sz=adj[u].size();

    for(int i=0;i<sz;i++)
    {
        int v=adj[u][i];

        if(bel[v]!=bel[u])
            ind[bel[v]]++;

        if(!vis[v])
	dfs(v);

    }
}

int main()
{
    int tc;
    cin>>tc;

    initialize();

    while(tc--)
    {
        int n,m;
        cin>>n>>m;

        while(m--)
        {
            int p,q;
            cin>>p>>q;
            adj[p].push_back(q);
        }

        for(int i=1;i<=n;i++)
            if(!vis[i])
                tarjan(i);

        memset(vis, 0, sizeof(vis));

        for(int i=1;i<=n;i++)
            if(!vis[i])
                dfs(i);

        int ans=0;

        for(int i=0;i<scc;i++)
            if(ind[i]==0)
                ans++;

        cout<<ans<<endl;

        clean(n);
    }

}
