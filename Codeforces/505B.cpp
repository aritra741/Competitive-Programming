#include<bits/stdc++.h>
#define mx 107
using namespace std;

vector<int>adj[mx][mx];
bool vis[mx];
int a,b;

bool dfs( int u, int c )
{
    if( u==b )
        return 1;
    vis[u]= 1;

    for( auto v: adj[c][u] )
    {
        if(vis[v])
            continue;

        if( dfs(v,c) )
            return 1;
    }

    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for( int i=0;i<m;i++ )
    {
        int p,q,c;
        cin>>p>>q>>c;

        adj[c][p].push_back(q);
        adj[c][q].push_back(p);
    }

    int q;
    cin>>q;

    while(q--)
    {
        cin>>a>>b;

        int cc= 0;

        for( int c=1;c<=100;c++ )
        {
            cc+= dfs(a,c);
            memset( vis, 0, sizeof(vis) );
        }

        cout<< cc <<"\n";
    }
}
