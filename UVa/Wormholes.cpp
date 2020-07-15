#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

struct edge
{
    int u,v,cost;
}edges[2020];

set<int> st;
set<int> ::iterator it;
vector<int> adj[1020];
bool vis[1020];
ll dist[1020];

void dfs(int x)
{
    st.insert(x);

    for(int i=0;i<adj[x].size();i++)
    {
        int u= adj[x][i];
        if(!vis[u])
        {
            vis[u]=1;
            dfs(u);
        }
    }
}

int main()
{
        int tc;
        cin>>tc;

        for(int t=1;t<=tc;t++)
        {
            int n,m;
            cin>>n>>m;

            for(int i=0;i<m;i++)
                {
                    int p,q,w;
                    cin>>p>>q>>w;
                    edges[i].v=p;
                    edges[i].u=q;
                    edges[i].cost=w;
                    adj[q].push_back(p);
                }

            fill(dist, dist+n, 1e16);
            st.clear();
            memset(vis, 0, sizeof(vis));

            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<m;j++)
                {
                    int p=edges[j].u;
                    int q=edges[j].v;
                    int w=edges[j].cost;
                    if( dist[q] > dist[p] + w )
                        dist[q] = dist[p] + w;
                }
            }

            bool cycle=0;

            for(int j=0;j<m;j++)
                {
                    int p=edges[j].u;
                    int q=edges[j].v;
                    int w=edges[j].cost;
                    if( dist[q] > dist[p] + w )
                        {
                            cycle=1;
                            if(!vis[p])
                                dfs(p);
                        }
                }

            if(!cycle)
                {
                    cout<<"not possible"<<endl;
                    for(int i=0;i<n;i++)
                    adj[i].clear();
                }
            else
            {
                cout<<"possible"<<endl;

                for(int i=0;i<n;i++)
                    adj[i].clear();
            }
        }
}

