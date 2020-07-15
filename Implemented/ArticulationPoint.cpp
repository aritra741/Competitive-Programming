#include <bits/stdc++.h>
#define MX 100007
using namespace std;

bool vis[MX];
int Time;
int par[MX],low[MX],d[MX],AP[MX];       ///d=discovery Time
vector<int> adj[MX];

void initialize()
{
    for(int i=0;i<MX;i++)
    {
        vis[i]=AP[i]=false;
        par[i]=-1;
        low[i]=0;
        adj[i].clear();
    }

    Time=0;

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

        if( !vis[v] )
        {
            par[v]=u;
            subtree++;
            dfs(v);

            low[u]= min( low[u], low[v] );

            if(par[u]!=-1 and low[v]>=d[u])             ///In articulation bridges however, root is not a special case and it's enough to compare low[v] and d[u]
                AP[u]=true;

            else if(par[u]==-1 and subtree>1)
                AP[u]=true;
        }

        else
        {
            low[u]= min( low[u], d[v] );
        }
    }
}

int main()
{

}

