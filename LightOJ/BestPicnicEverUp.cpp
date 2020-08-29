#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int hit[1010];
bool vis[1010];
bool source[1010];
vector <int> adj[1010];

void dfs(int x)
{
    for(int i=0; i<adj[x].size(); i++)
    {
        int u=adj[x][i];
        if(!vis[u])
        {
            vis[u]=1;
            hit[u]++;
            dfs(u);
        }
    }
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        int k,n,m;
        cin>>k>>n>>m;

        memset(source, 0, sizeof(source));
        memset(hit, 0, sizeof(hit));
        set <int> st;
        for(int i=0; i<k; i++)
        {
            int p;
            cin>>p;
            source[p]=1;
            hit[p]=1;
            st.insert(p);
        }

        k=st.size();

        for(int i=0; i<m; i++)
        {
            int p,q;
            cin>>p>>q;
            adj[p].push_back(q);
        }

        for(int i=1; i<=n; i++)
        {
            if(source[i])
            {
                vis[i]=1;
                dfs(i);
                memset(vis, 0, sizeof(vis));
            }
        }

        int cnt=0;

        for(int i=1; i<=n; i++)
        {
            cout<<i<<"->"<<hit[i]<<endl;
            if(hit[i]==k)
                cnt++;
        }

        cout<<"Case "<<t<<": "<<cnt<<endl;

        for(int i=1;i<=n;i++)
            adj[i].clear();

    }
}
