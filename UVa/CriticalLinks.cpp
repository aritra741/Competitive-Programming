#include <bits/stdc++.h>
#define pii pair<int,int>
#define dbg(x) cout<<x<<endl
#define MX 100007
using namespace std;

bool vis[MX];
int par[MX],low[MX],d[MX];
vector <int> adj[MX];
int Time;
set <pii> st;
set <pii> ::iterator it;

void initialize()
{
    for(int i=0;i<MX;i++)
        par[i]=-1;
    Time=0;
}

void clean(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=-1;
        vis[i]=false;
        low[i]=0;
        adj[i].clear();
    }
    Time=0;
    st.clear();
}

void dfs(int u)
{
    vis[u]=1;
    low[u]=d[u]=(++Time);

    int subtree=0;
    int sz=adj[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=adj[u][i];

        if(v==par[u])
            continue;

        if(!vis[v])
        {
            vis[v]=1;
            subtree++;
            par[v]=u;

            dfs(v);

            low[u]=min( low[u], low[v] );

            if(low[v]>d[u])
            {
                int p=max(u,v);
                int q=min(u,v);
                st.insert( pii(q,p) );
            }

        }

        else
            low[u]=min( low[u], d[v] );
    }

}

int main()
{
        initialize();

        int n;
        while(scanf("%d", &n)==1){

        for(int i=0;i<n;i++)
        {
            int p,j,q;
            scanf("%d (%d)", &p,&j);

            for(int k=0;k<j;k++)
            {
                scanf("%d", &q);
                adj[p].push_back(q);
            }
        }

        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i);

        int sz=st.size();
        printf("%d critical links\n", sz);

        for(it=st.begin();it!=st.end();it++)
            printf("%d - %d\n", it->first, it->second);
        printf("\n");

        clean(n);

        }
}

