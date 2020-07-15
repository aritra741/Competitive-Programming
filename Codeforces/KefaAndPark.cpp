#include <bits/stdc++.h>
#define mx 100007
using namespace std;

vector<int> adj[mx];
bool vis[mx];
bool cat[mx];
int n,m,ans;

void dfs( int u, int cnt )
{
    vis[u]= 1;
    int sz= adj[u].size();

    if( cnt>m )
        return;

    if( sz==1 and u!=1 )
        ans++;

    for(int i=0;i<sz;i++)
    {
        int v= adj[u][i];

        if(vis[v])
            continue;
        int now= cnt;

        if(cat[v]==1)
            now++;
        else
            now= 0;

        dfs( v, now );
    }
}

int main()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>cat[i];

    for(int i=1;i<n;i++)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    dfs( 1, cat[1]==1 );

    cout<< ans <<endl;
}
