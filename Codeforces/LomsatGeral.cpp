#include <bits/stdc++.h>
#define mx 100007
using namespace std;

int color[mx], Max[mx], ans[mx];
vector<int> adj[mx];
map<int, int> mp[mx];
map<int, int> ::iterator it;

void combine( int x, int y )
{
    int big, small;
    if( mp[x].size()>mp[y].size() )
        big= x, small= y;
    else
        big= y, small =x;

    for( it=mp[small].begin();it!=mp[small].end();it++ )
        {
            mp[big][it->first]+= mp[small][it->first];
            int tot= mp[big][it->first];

            if( Max[it->first]<tot )
                Max[it->first]=tot;
            else if( ans[it->first]==tot )


        }

}

void dfs( int u, int par )
{
    mp[u][col[u]]= 1;

    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];

        if( v==par )
            continue;
        dfs( v, u );
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=1;i<=n;i++ )
        scanf("%d", &color[i]);

    for( int i=1;i<n;i++ )
    {
        int p,q;
        scanf("%d %d", &p, &q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    dfs( 1,0 );
}
