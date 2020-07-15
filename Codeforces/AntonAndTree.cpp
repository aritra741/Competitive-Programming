#include <bits/stdc++.h>
using namespace std;

vector<int>adj[200007];
bool col[200007], vis[200007];
int cmp[200007], cnt, mx= -1, node;

void dfs( int u, int tot )
{
    vis[u]= 1;

    if( tot==-1 )
        cmp[u]= cnt;

    if( tot>mx )
        mx= tot,node= u;

    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];

        if( vis[v] )
            continue;
        if( tot==-1 and col[u]!=col[v] )
            continue;

        int now= tot;
        if( tot!=-1 and cmp[v]!=cmp[u] )
            now++;

        dfs(v,now);
    }
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
        cin>> col[i];

    for( int i=1;i<n;i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    for( int i=1;i<=n;i++ )
    {
        if( vis[i] )
            continue;
        dfs(i,-1);
        cnt++;
    }

    memset( vis, 0, sizeof(vis) );

    mx= -1;
    int ans;
    dfs(1,0);
    mx= -1;
    memset(vis,0,sizeof(vis));
    dfs(node,0);

    cout<< (mx+1)/2 <<endl;
}
