#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10007], v;
bool vis[10007];
int con[10007];
int nxt,mx;

void dfs( int u, int cnt )
{
    vis[u]= 1;
    if( cnt>mx )
        mx= cnt, nxt= u;

    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];

        if( vis[v] )
            continue;
        int now= cnt;

        if( con[u]!=v )
            now++;

        dfs(v,now);
    }
}

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    int n;
    cin>>n;

    int add= 0;
    for(int j=0;j<n;j++)
    {
        int m;
        cin>>m;

        for( int i=1;i<m;i++ )
        {
            int p,q;
            cin>>p>>q;

            p+= add;
            q+= add;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        add+= m;
    }

    int prev= -1;
    int first= 1;
    for(int i=1;i<=add;i++)
    {
        if( vis[i] )
            continue;

        mx= -1;
        dfs( i,0 );
        if( prev!=-1 )
            v.push_back( prev ),
            v.push_back( nxt );
        if(prev==-1)
            first= nxt;
        memset( vis, 0, sizeof(vis) );
        mx= -1;
        dfs( nxt,0 );
        prev= nxt;
    }

    for( int i=1;i<v.size();i+=2 )
        adj[ v[i-1] ].push_back( v[i] ),
        adj[ v[i] ].push_back( v[i-1] ),
        con[v[i-1]]= v[i],
        con[v[i]]= v[i-1];

    memset( vis,0,sizeof(vis) );
    mx= -1;
    dfs( first,0 );
    memset( vis,0,sizeof(vis) );
    mx= -1;
    dfs( nxt,0 );

    cout<< mx <<endl;
}
