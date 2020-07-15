#include <bits/stdc++.h>
#define mx 100007
using namespace std;

vector <int> adj[mx];
bool vis[mx];
queue <int> q;
int lvl[mx];
int descendant[mx];

void bfs()
{
    vis[1]= 1;
    lvl[1]= 1;
    q.push(1);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        int sz= adj[u].size();

        for(int i=0;i<sz;i++)
        {
            int v= adj[u][i];
            if( !vis[v] )
            {
                vis[v]= 1;
                lvl[v]= lvl[u]+1;

                q.push(v);
            }
        }
    }
}

void dfs( int u )
{
    vis[u]= 1;
    int sz= adj[u].size();

    descendant[u]=1;

    for(int i=0;i<sz;i++)
    {
        int v= adj[u][i];

        if(!vis[v])
        {
            dfs(v);
            descendant[u]+=descendant[v];
        }
    }



}

int main()
{
    int n;
    cin>>n;

    for(int i=2;i<=n;i++)
    {
        int p;
        cin>>p;

        adj[p].push_back(i);
    }

    bfs();
    memset(vis, 0, sizeof(vis));
    dfs(1);

    for(int i=1;i<=n;i++)
       cout<<(double)(lvl[i]+0.5*(n-descendant[i]-lvl[i]))+0.5<<" ";


}
