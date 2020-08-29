#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int vis[1010];
bool done[1010];
bool visited[1010];
bool peeps[1010];
vector <int> adj[1010];
int increase=1;

void dfs(int x)
{
    for(int i=0; i<adj[x].size(); i++)
    {
        int u=adj[x][i];
        if(peeps[u] and !done[u] and !visited[u])
        {
            increase++;
            visited[u]=1;
            done[u]=1;
            vis[u]+=increase-1;
            dfs(u);
        }
        else if(!visited[u]){
        vis[u]+=increase;
        visited[u]=1;
        dfs(u);
        }

//        else if(visited[u])
//        {
//            if(peeps[i])
//                vis[u]+=increase-1;
//            else
//                vis[u]+=increase;
//        }
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

        memset(peeps, 0, sizeof(peeps));
        memset(vis, 0, sizeof(vis));
        memset(done, 0, sizeof(done));
        set <int> st;
        increase=1;

        for(int i=0; i<k; i++)
        {
            int p;
            cin>>p;
            peeps[p]=1;
            st.insert(p);
            vis[p]=1;
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
            if(peeps[i] and !done[i])
            {
               // cout<<"Ekhon "<<i<<endl;
                memset(visited,0 , sizeof(visited));
                visited[i]=1;
                done[i]=1;
                dfs(i);
                increase=1;
            }
        }

        int cnt=0;

        for(int i=1; i<=n; i++)
        {
           // cout<<i<<"->"<<vis[i]<<endl;
            if(vis[i]==k)
                cnt++;
        }

        cout<<"Case "<<t<<": "<<cnt<<endl;

        for(int i=1;i<=n;i++)
            adj[i].clear();

    }
}
