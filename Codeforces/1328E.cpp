#include<bits/stdc++.h>
#define mx 200007
using namespace std;

vector<int>adj[mx];
int par[mx][20], lvl[mx];
int qq[mx];

void bfs( int x )
{
    queue<int>q;
    q.push(x);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for( auto v: adj[u] )
        {
            if(par[u][0]==v)
                continue;
            par[v][0]= u;
            lvl[v]= lvl[u]+1;
            q.push(v);
        }
    }
}

int lca(int u,int v)
{
    if(lvl[u]<lvl[v])
        swap(u,v);
    for(int k=19; k>=0; k--)
        if(lvl[par[u][k]]>=lvl[v])
            u=par[u][k];
    if(u==v)
        return u;
    for(int k=19; k>=0; k--)
        if(par[u][k]!=par[v][k])
            u=par[u][k],v=par[v][k];
    return par[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    for( int i=1; i<n; i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    par[1][0]= 1;
    bfs(1);

    for( int j=1; j<20; j++ )
        for( int i=1; i<=n; i++ )
            par[i][j]= par[par[i][j-1]][j-1];

    while(q--)
    {
        int k;
        cin>>k;

        int last= 0;

        for( int i=0;i<k;i++ )
        {
            cin>>qq[i];

            if( lvl[ qq[i] ]>=lvl[last] )
                last= qq[i];
        }

        bool f= 1;

        for( int i=0;i<k;i++ )
        {
            if( last==qq[i] )
                continue;

            if( lca( qq[i], last )!=qq[i] and lca( qq[i], last )!=par[qq[i]][0] )
            {
                f= 0;
                break;
            }
        }

        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
