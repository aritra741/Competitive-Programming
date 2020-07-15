#include <bits/stdc++.h>
using namespace std;

bool vis[1010];
vector <int> adj[1010];
int ans;

void cycle( int x )
{
    int sz=adj[x].size();

    for(int i=0;i<sz;i++)
    {
        int u=adj[x][i];
        if(!vis[u])
        {
            vis[u]=1;
            cycle(u);
        }

        else
            ans=u;
    }
}


int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        adj[i].push_back(p);
    }

    for(int i=1;i<=n;i++)
    {
        memset(vis, 0, sizeof(vis));
        vis[i]=1;
        cycle(i);
        cout<<ans<<" ";

    }
}
