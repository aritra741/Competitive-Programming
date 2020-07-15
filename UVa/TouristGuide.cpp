#include <bits/stdc++.h>
#define MX 110
using namespace std;

bool vis[MX];
int par[MX], low[MX], d[MX];
vector <int> adj[MX];
set <string> st;
set <string> ::iterator it;
map <string, int> stToi;
map <int, string> intTost;
int Time;

void initialize()
{
    for(int i=0;i<MX;i++)
        par[i]=-1;
    Time=0;
}

void clean()
{
    Time=0;

    for(int i=0;i<MX;i++)
    {
        par[i]=-1;
        low[i]=0;
        vis[i]=false;
        adj[i].clear();
    }

    st.clear();
    stToi.clear();
    intTost.clear();
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
                st.insert(intTost[u]);
            else if(par[u]==-1 and subtree>1)
                st.insert(intTost[u]);
        }

        else
            low[u]=min( low[u], d[v] );
    }


}

int main()
{
    initialize();
    int tc=1;

    while(1)
    {
        int n;
        cin>>n;

        if(!n)
            break;

        if(tc!=1)
            cout<<endl;

        int cnt=0;

        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            stToi[s]=++cnt;
            intTost[cnt]=s;
        }

        int edge;
        cin>>edge;

        while(edge--)
        {
            string s,t;
            cin>>s>>t;

            adj[stToi[s]].push_back(stToi[t]);
            adj[stToi[t]].push_back(stToi[s]);
        }

        for(int i=1;i<=cnt;i++)
            if(!vis[i])
                dfs(i);

        cout<<"City map #"<<tc++<<": "<<st.size()<<" camera(s) found"<<endl;

        for(it=st.begin();it!=st.end();it++)
            cout<< *it <<endl;

        clean();

    }
}

