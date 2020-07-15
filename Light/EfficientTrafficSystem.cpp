#include <bits/stdc++.h>
#define mx 20007
using namespace std;

vector <int> adj[mx];
bool vis[mx], stck[mx];
int t=0, cnt=0;
int low[mx], d[mx], scc[mx], ind[mx], outd[mx];
stack<int> st;

/// vis[ something ] = 0 indicates that we haven't traversed it even once
/// vis[ something ] = 1 could mean 2 different things. Either it is already a part of an SCC or it's still in stack. We don't work with
/// the first type.
void clean()
{
    for(int i=0; i<mx; i++)
        adj[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(low, 0, sizeof(low));
    memset(ind, 0, sizeof(ind));
    memset(outd, 0, sizeof(outd));
    memset(d, 0, sizeof(d));
    memset(scc, -1, sizeof(scc));

    t= 0;

    while(!st.empty())
        st.pop();

    cnt= 0;
}

void tarjan(int u)
{
    low[u]=d[u]=++t;
    int sz= adj[u].size();
    vis[u]= 1;
    stck[u]= 1;
    st.push(u);

    for(int i=0; i<sz; i++)
    {
        int v= adj[u][i];

        if(!vis[v])
        {
            tarjan( v );

            low[u]= min( low[u], low[v] );
        }

        else if(stck[v])
            low[u]= min( low[u], d[v] );
    }

    if(low[u]==d[u])
    {

        while(!st.empty() and st.top()!=u)
        {
            int v= st.top();
            st.pop();
            scc[v]= cnt;
            stck[v]= 0;
        }
        if(!st.empty() and st.top()==u)
        {
            st.pop();
            scc[u]= cnt;
            stck[u]= 0;
        }

        cnt++;
    }
}

void dfs( int u )
{
    vis[u]= 1;
    int sz= adj[u].size();

    for(int i=0; i<sz; i++)
    {
        int v= adj[u][i];

        if(scc[u]!=scc[v])
        {
            ind[scc[v]]++;
            outd[scc[u]]++;
        }

        if(!vis[v])
            dfs(v);
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t=1; t<=tc; t++)
    {
        getchar();

        int n,m;
        scanf("%d %d", &n, &m);

        for(int i=0; i<m; i++)
        {
            int p,q;
            scanf("%d %d", &p, &q);

            adj[p].push_back(q);
        }

        for(int i=1; i<=n; i++)
            if(!vis[i])
                tarjan(i);

        memset(vis, 0, sizeof(vis));

        for(int i=1; i<=n; i++)
            if(!vis[i])
                dfs(i);

        int totIn=0, totOut=0;

        for(int i=0; i<cnt and cnt>1; i++)
        {
            if(!ind[i])
                totIn++;
            if(!outd[i])
                totOut++;
        }

        printf("Case %d: %d\n", t, max(totIn, totOut));

        clean();
    }
}
