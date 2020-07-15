#include <bits/stdc++.h>
#define mx 200007
using namespace std;

vector<int> adj[mx];
int vis[mx], state[mx];
bool cycle;
int nodecnt, edgecnt, nodesincycle;

void dfs(int u, int par)
{
    vis[u]= 1;
    int sz= adj[u].size();

    for(int i=0; i<sz; i++)
    {
        int v= adj[u][i];

        if(!vis[v])
        {
            state[v]= state[u]+1;
            nodecnt++, edgecnt++;
            dfs(v, u);
        }

        else if(par!=v and vis[v]==1)
            edgecnt++,cycle= 1, nodesincycle= abs(state[v]-state[u])+1;
    }

    vis[u]=2;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    int ans= 0;

    for(int i=1; i<=n; i++)
    {
        nodecnt= 1, edgecnt=0, cycle= 0, nodesincycle= 1;
        if(!vis[i])
        {
            state[i]= 1;
            dfs(i, -1);
        }
        if(cycle and nodecnt==edgecnt and nodesincycle==nodecnt)
            ans++;
    }

    cout<<ans<<endl;
}
