#include<bits/stdc++.h>
#define mx 200007
using namespace std;

vector<int>adj[mx],marked,vv;
bool mark[mx], vis[mx];
int lvl[mx], paare[mx];
int pore_lvl[mx];
bool paisi;
int parena;
int n,m,k;

bool cmp( int a, int b )
{
    return lvl[a]<lvl[b];
}

void bfs( int x )
{
    queue<int>q;
    q.push(x);
    vis[x]= 1;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for( auto v: adj[u] )
        {
            if(vis[v])
                continue;

            lvl[v]= lvl[u]+1;
            vis[v]= 1;
            q.push(v);
        }
    }
}

void bfs2( int x )
{
    queue<int>q;
    q.push(x);
    vis[x]= 1;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for( auto v: adj[u] )
        {
            if(vis[v])
                continue;

            pore_lvl[v]= pore_lvl[u]+1;
            vis[v]= 1;
            q.push(v);
        }
    }
}

bool dfs1( int u )
{
    if(u==n)
        return paare[u]= 1;

    vis[u]= 1;
    bool f= 0;

    for( auto v: adj[u] )
    {
        if(vis[v])
            continue;
        f|= dfs1(v);
    }

    if(mark[u] and !f)
        paisi= 1;

    return paare[u]= f;
}

bool dfs2( int u )
{
    if(u==n )
    {
        if( mark[u] )
            vv.push_back(u);
        return 1;
    }

    vis[u]= 1;
    bool f= 0;

    for( auto v: adj[u] )
    {
        if(vis[v] or !paare[v] )
            continue;
        f|= dfs2(v);
    }

    if( mark[u] )
        vv.push_back(u);

    return f;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;

    for( int i=0;i<k;i++ )
    {
        int p;
        cin>>p;

        mark[p]= 1;
        marked.push_back(p);
    }

    for( int i=0;i<m;i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    bfs(1);

    memset( vis, 0, sizeof(vis) );

    bool ok= dfs1(1);

    if(paisi)
        return cout<<lvl[n]<<endl, 0;

    memset( vis, 0, sizeof(vis) );

    ok= dfs2(1);

    sort( vv.begin(), vv.end(), cmp );+

    memset( vis, 0, sizeof(vis) );

    bfs2( n );

    int emni= 0;

    for( int i=1;i<vv.size();i++ )
    {
        int add= 0;
        if( lvl[ v[i] ]!=lvl[ v[i-1] ] )
            add++;
        emni= max( emni, pore_lvl[ vv[i-1] ]+lvl[ vv[i] ]+add);
    }
    cout<< emni;
}
