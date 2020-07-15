#include <bits/stdc++.h>
#define mx 10007
using namespace std;

vector<int>adj[mx];
int lvl[mx], par[mx][25];
int root;
bool notRoot[mx];

void dfs( int u, int cnt )
{
    lvl[u]= cnt;
    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];

        par[v][0]= u;
        dfs(v,cnt+1);
    }
}

void pre( int n )
{
    for( int j=1;(1<<j)<=n;j++ )
        for( int i=1;i<=n;i++ )
            if( par[i][j-1]!=-1 )
                par[i][j]= par[ par[i][j-1] ][j-1];
}

int query( int p, int q )
{
    if( lvl[p]<lvl[q] )
        swap( p,q );

    int log= 0;

    while(1)
    {
        int next= log+1;

        if( (1<<next)>lvl[p] )
            break;
        log++;
    }

    for( int j=log;j>=0;j-- )
        if( (lvl[p]-(1<<j))>=lvl[q] )
            p= par[p][j];

    if(p==q)
        return q;

    for( int i=log;i>=0;i-- )
        if( par[p][i]!=-1 and par[p][i]!=par[q][i] )
            p= par[p][i], q= par[q][i];

    return par[p][0];
}

void clean( int n )
{
    root= 0;
    for( int i=0;i<=n;i++ )
        lvl[i]= 0,
        adj[i].clear(),
        notRoot[i]= 0;
    for( int i=0;i<=n;i++ )
        for( int j=0;j<25;j++ )
            par[i][j]= -1;
}

int main()
{
    int tc;
    cin>>tc;

    for( int t=1;t<=tc;t++ )
    {
        int n;
        scanf("%d", &n);
        clean(n);

        for( int i=1;i<=n;i++ )
        {
            int m;
            scanf("%d", &m);

            for( int j=0;j<m;j++ )
            {
                int p;
                scanf("%d", &p);

                adj[i].push_back(p);
                notRoot[p]= 1;
            }
        }

        for( int i=1;i<=n;i++ )
            if( !notRoot[i] )
                root= i;

        dfs( 1, 0 );
        pre(n);

        int qu;
        scanf("%d", &qu);
        printf("Case %d:\n", t);

        while(qu--)
        {
            int p,q;
            scanf("%d %d", &p, &q);

            int ans= query( p,q );

            printf("%d\n", ans);
        }
    }
}

