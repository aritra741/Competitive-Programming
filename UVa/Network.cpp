#include <bits/stdc++.h>
#define MX 110
using namespace std;

bool vis[MX];
int par[MX], low[MX], d[MX];
vector<int> adj[MX];
set<int> st;
int Time;

void initialize()
{
    for(int i=0;i<MX;i++)
        par[i]=-1;
    Time=0;
}

void clean()
{
    for(int i=0;i<MX;i++)
    {
        par[i]=-1;
        vis[i]=0;
        adj[i].clear();
        low[i]=0;
    }

    st.clear();

}

void dfs(int u)
{
    vis[u]=1;
    low[u]=d[u]=++Time;
    int subtree=0;
    int sz=adj[u].size();

    for(int i=0;i<sz;i++)
    {
        int v=adj[u][i];
        if(par[u]==v)
            continue;

        if(!vis[v])
        {
            par[v]=u;
            subtree++;

            dfs(v);

            low[u]= min( low[u], low[v] );

            if(par[u]!=-1 and d[u]<=low[v])
                st.insert(u);
            else if(par[u]==-1 and subtree>1)
                st.insert(u);
        }

        else
            low[u]= min(d[v], low[u]);
    }
}

int main()
{
    initialize();
    while(1)
    {
        int n;
        cin>>n;
        getchar();
        if(!n)
            break;

        string s;

        while(getline(cin,s))
        {
            stringstream ss;
            ss<<s;

            int u;
            ss>>u;

            if(!u)
            {
                for(int i=1;i<=n;i++)
                    if(!vis[i])
                        dfs(i);

                cout<<st.size()<<endl;
                clean();
                break;
            }

            int v;
            while(ss>>v)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }


    }
}
