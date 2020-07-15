#include<bits/stdc++.h>
#define mx 407
using namespace std;

int n,m;
vector<int>adj[mx];
int lvl[mx];
bool mat[mx][mx], vis[mx];

void bfs( int p )
{
    queue<int>q;
    vis[p]= 1;
    q.push(p);
    lvl[p]= 0;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for( auto v: adj[u] )
        {
            if( vis[v] )
                continue;

            vis[v]= 1;
            lvl[v]= lvl[u]+1;
            q.push(v);
        }
    }
}

int main()
{
    cin>>n>>m;

    for( int i=0;i<m;i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);

        mat[p][q]= 1;
        mat[q][p]= 1;
    }

    memset( lvl, 0x3f, sizeof(lvl) );
    memset( vis, 0, sizeof(vis) );

    bfs(1);

    if( !vis[n] )
        return cout<<"-1\n", 0;

    int ans= lvl[n];

    memset( lvl, 0x3f, sizeof(lvl) );
    memset( vis, 0, sizeof(vis) );

    for( int i=1;i<=n;i++ )
        adj[i].clear();

    for( int i=1;i<=n;i++ )
        for( int j=i+1;j<=n;j++ )
            if( !mat[i][j] )
                adj[i].push_back(j),
                adj[j].push_back(i);

    bfs(1);

    if( !vis[n] )
        return cout<<"-1\n", 0;

    ans= max(ans,lvl[n]);

    cout<<ans<<endl;
}
