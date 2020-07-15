#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector <int> adj[200005];
int ans,p;
bool vis[200005];
bool first=1;
int reach[200005];
int sequence[200005];
int cnt=1;
int idx=0;
int locate[200005];

void dfs(int x)
{
    sequence[idx++]=x;
    locate[x]=idx-1;
    for(int i=0;i<adj[x].size();i++)
        if(!vis[adj[x][i]])
        {
            vis[adj[x][i]]=1;
            dfs(adj[x][i]);
            reach[x]+=reach[adj[x][i]];
        }
}

int main()
{
    int n,q;
    cin>>n>>q;
    int temp;
    for(int i=2;i<=n;i++)
    {
        cin>>temp;
        adj[temp].pb(i);
    }
    for(int i=0;i<=n;i++)
        reach[i]=1;
    dfs(1);
    int u;
    for(int i=0;i<q;i++)
    {
        cin>>u>>p;
        if(p>reach[u])
        {
            cout<<"-1"<<endl;
            continue;
        }

        cout<<sequence[locate[u]-1+p]<<endl;

    }
}
