#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

vector<int> adj[510];
vector<pii> nds;
int st[510], out[510], in[510], root, cnt, a, b;
bool cycle, found, valid;

void dfs( int u )
{
    if(cycle)
        return;
    st[u]= 1;
    bool now= 0;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v= adj[u][i];

        if(now)
            break;

        if( st[v]==1 )
            cycle= 1, root= v, cnt++;

        if( !st[v] )
            dfs(v);

        if(found)
            break;

        if( cycle and !now )
            now= 1,
            nds.push_back( pii(u,v) );
    }

    if( cycle )
    {
        if(found)
            return;
        if( u==root )
            found= 1;
    }

    st[u]= 2;
}

void dfs2( int u )
{
    if(cycle)
        return;

    st[u]= 1;

    for(int i=0; i<adj[u].size(); i++)
    {
        int v= adj[u][i];

        if( a==u and v==b )
            continue;

        if( st[v]==1 )
        {
            cycle= 1;
            break;
        }

        else if( !st[v] )
            dfs2(v);
    }

    st[u]= 2;
}

int main()
{
    int n,m;
    cin>>n>>m;

    while(m--)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
    }

    for(int i=1; i<=n; i++)
        if( !st[i] )
            dfs(i);

    if(!cnt)
    {
        cout<<"YES\n";
        return 0;
    }

    cycle= 0, valid= 1;

    for(int i=0; i<nds.size(); i++)
    {
        a= nds[i].f, b= nds[i].s;

        memset(st,0,sizeof(st));
        valid= 1;

        for(int j=1; j<=n; j++)
        {
            if( st[j] )
                continue;
            dfs2( j );
            if( cycle )
                valid= 0;
        }

        if( valid )
        {
            cout<<"YES\n";
            return 0;
        }

        cycle= 0;
    }

    cout<<"NO\n";
}

/*
4 5
1 3
3 2
2 1
3 4
4 1
*/
