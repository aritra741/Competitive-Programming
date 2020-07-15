#include<bits/stdc++.h>
#define mx 200007
using namespace std;

vector<int>adj[mx];
int col[mx];
bool vis[mx];
vector<int>a,b;

void dfs( int u )
{
    vis[u]= 1;

    for( auto v: adj[u] )
    {
        if( vis[v] )
            continue;
        if( col[u]==1 )
            col[v]= 2, b.push_back(v);
        else
            col[v]= 1, a.push_back(v);

        dfs(v);
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n,m;
        scanf("%d %d", &n,&m);

        for( int i=0;i<m;i++ )
        {
            int p,q;
            scanf("%d %d", &p, &q);

            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        a.push_back(1);
        col[1]= 1;
        dfs(1);

        if( a.size()<b.size() )
        {
            printf("%d\n", a.size());

            for( auto x: a )
                printf("%d ", x);
            printf("\n");
        }
        else
        {
            printf("%d\n", b.size());

            for( auto x: b )
                printf("%d ", x);
            printf("\n");
        }

        for( int i=1;i<=n;i++ )
            adj[i].clear(),
            col[i]= 0,
            vis[i]= 0;

        a.clear();
        b.clear();
    }
}
