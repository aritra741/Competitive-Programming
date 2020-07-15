#include <bits/stdc++.h>
#define MX 4000
using namespace std;

int low[MX], d[MX];
bool vis[MX], scc[MX];
int Time,n;
set <int> SCC;
vector <int> adj[MX];
stack <int> st;
bool flag=0;

void clean(int n)
{
    for(int i=0;i<=n;i++)
        {
            low[i]=d[i]=vis[i]=scc[i]=0;
            adj[i].clear();
        }
    SCC.clear();
    st= stack<int>();
    Time=0;
    flag=0;
}

void tarjan(int u)
{
    vis[u]=1;
    low[u]=d[u]=++Time;
    st.push(u);

    int sz= adj[u].size();

    for(int i=0;i<sz;i++)
    {
        int v=adj[u][i];

        if(!vis[v])
        {
            tarjan(v);

            low[u]= min(low[u], low[v]);
        }

        else if(!scc[v])
            low[u]= min( low[u], d[v] );
    }

    if(low[u]==d[u])
    {

        scc[u]=1;
        SCC.insert(u);
        while(st.top()!=u)
        {
            int v=st.top();
            scc[v]=1;
            st.pop();
            SCC.insert(v);
        }

        if(!st.empty() and st.top()==u)
            st.pop();

        if(SCC.size()==n)
            flag=1;
        SCC.clear();
    }
}

int main()
{
    while(1)
    {
        int m;
        cin>>n>>m;

        if(n+m==0)
            break;

        while(m--)
        {
            int p,q,w;
            cin>>p>>q>>w;

            adj[p].push_back(q);

            if(w==2)
                adj[q].push_back(p);
        }

        for(int i=1;i<=n;i++)
            if(!vis[i])
                tarjan(i);

        if(flag)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;

        clean(n);
    }

}

