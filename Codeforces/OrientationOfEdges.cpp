#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int v,tp,idx,first;

    edge( int _v, int _tp, int _idx, int _first )
    {
        v= _v, tp= _tp, idx= _idx, first= _first;
    }
};

vector<edge>adj[300007];
bool dir[300007], vis[300007];
int cnt= 0, undir= -1;

void dfs1( int u )
{
    vis[u]= 1;
    cnt++;

    for( int i=0;i<adj[u].size();i++ )
    {
        edge now= adj[u][i];
        int v= now.v;
        int tp= now.tp;
        int idx= now.idx;
        int first= now.first;

        if( vis[v] )
            continue;

        if( tp==2 )
        {
            if( first )
                dir[idx]= 1;
            dfs1( v );
        }
        else
            dfs1( v );
    }
}

void dfs2( int u )
{
    vis[u]= 1;
    cnt++;

    for( int i=0;i<adj[u].size();i++ )
    {
        edge now= adj[u][i];
        int v= now.v;
        int tp= now.tp;
        int idx= now.idx;
        int first= now.first;

        if( vis[v] )
            continue;

        if( tp==2 )
        {
            if( first )
                dir[idx]= 1;
        }
        else
            dfs2( v );
    }
}

int main()
{
    int n,m,s;
    cin>>n>>m>>s;

    for(int i=0;i<m;i++)
    {
        int t,p,q;
        cin>>t>>p>>q;

        if( t==2 )
            undir++;

        adj[p].push_back( edge(q,t,undir,1) );
        if( t==2 )
            adj[q].push_back( edge(p,t,undir,0) );
    }

    dfs1(s);

    cout<<cnt<<endl;
    for( int i=0;i<=undir;i++ )
        cout<< (dir[i]?'+':'-');
    cout<<endl;

    memset( vis,0,sizeof(vis) );
    memset( dir,0,sizeof(dir) );
    cnt= 0;
    dfs2(s);

    cout<<cnt<<endl;
    for( int i=0;i<=undir;i++ )
        cout<< (dir[i]?'-':'+');
    cout<<endl;

}
