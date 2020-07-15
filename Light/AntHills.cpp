#include <bits/stdc++.h>
#define MX 100007
#define dbg(x) cout<<x<<endl;
using namespace std;

int Time;
int d[MX], low[MX],par[MX];
bool vis[MX];
vector <int> adj[MX];
set <int> AP;

void initialize(int mx)
{
    for(int i=0; i<=mx; i++)
        par[i]=-1;
    Time=0;
}

void clean(int mx)
{
    for(int i=0; i<=mx; i++)
    {
        vis[i]=false;
        low[i]=0;
        par[i]=-1;
        adj[i].clear();
    }

    AP.clear();
    Time=0;
}

void dfs(int u)
{
    vis[u]=1;
    low[u]=d[u]=++Time;

    int subtree=0;
    int sz=adj[u].size();

    for(int i=0; i<sz; i++)
    {
        int v=adj[u][i];

        if(v==par[u])
            continue;

        if(!vis[v])
        {
            par[v]=u;
            subtree++;
            dfs(v);

            low[u]= min( low[u], low[v] );

            if(par[u]!=-1 and low[v]>=d[u])
                AP.insert(u);
            if(par[u]==-1 and subtree>1)
                AP.insert(u);
        }

        else
            low[u]= min( low[u], d[v] );


    }
}

int main()
{
    initialize(MX);
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        getchar();
        int n,m;
        cin>>n>>m;

        for(int j=0; j<m; j++)
        {
            int p,q;
            cin>>p>>q;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        dfs(1);

        cout<<"Case "<<t<<": "<<AP.size()<<endl;

        clean(n);

    }
}
