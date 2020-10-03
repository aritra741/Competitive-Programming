#include <bits/stdc++.h>
#define mx 507
using namespace std;

int aa[mx], bb[mx];
vector<int> adj[mx];
bool vis[mx];
int mr[mx], ml[mx];

int dfs( int y )
{
    vis[y] = 1;
    for ( int i = 0; i < adj[y].size(); i++ )
    {
        int z = adj[y][i];

        if ( mr[z] == -1 or (!vis[ mr[z] ]  and dfs( mr[z] ) ) )
        {
            ml[y] = z;
            mr[z] = y;
            return 1;
        }
    }

    return 0;
}

int main()
{
    memset( mr, -1, sizeof(mr) );
    memset( ml, -1, sizeof(ml) );

    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);

    while(k--)
    {
        int u,v;
        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
    }

    int ans = 0;
    for ( int i = 1; i <= n; i++ )
    {
        memset( vis, 0, sizeof(vis) );

        ans += dfs( i );
    }

    cout<< ans <<"\n";

    for( int i=1;i<=n;i++ )
        if( ml[i]!=-1 )
            cout<<i<<" "<<ml[i]<<"\n";
}

