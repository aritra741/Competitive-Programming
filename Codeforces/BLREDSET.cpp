#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mx 200007
using namespace std;

vector<int>adj[mx];
int col[mx], col_und[mx][3];
ll total[mx], total_kharap[mx];
bool bhalo[mx];

void clean( int n )
{
    for( int i=1;i<=n;i++ )
        adj[i].clear(), total[i]= 0,
        total_kharap[i]= 0, bhalo[i]= 0,
        col_und[i][0]= col_und[i][1]= col_und[i][2]= 0;
}

void dfs( int u, int p )
{
    col_und[u][ col[u] ]++;

    bool hasred= 0, hasblack= 0;

    for( auto v: adj[u] )
    {
        if( v==p )
            continue;

        dfs( v,u );

        bhalo[u]|= !col[u] and hasblack and col_und[v][2];
        bhalo[u]|= !col[u] and hasred and col_und[v][1];

        hasblack|= col_und[v][1]>0;
        hasred|= col_und[v][2]>0;

        for( int i=0;i<3;i++ )
            col_und[u][i]+= col_und[v][i];
    }
}

void dfs2( int u, int p )
{
    if( !col[u] )
        total[u]++;
    if( !col[u] and !bhalo[u] )
        total_kharap[u]++;

    for( auto v: adj[u] )
    {
        if(v==p)
            continue;

        dfs2( v,u );

        total[u]= (total[u]*( total[v]+1 ))%mod;
        total_kharap[u]= (total_kharap[u]*( total_kharap[v]+1 ))%mod;
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        for( int i=1;i<n;i++ )
        {
            int p,q;
            scanf("%d %d", &p, &q);

            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        for( int i=1;i<=n;i++ )
            scanf("%d", &col[i]);

        dfs(1,1);

        for( int i=1;i<=n;i++ )
            bhalo[i]|= !col[i] and col_und[i][2] and col_und[1][1]-col_und[i][1]>0,
            bhalo[i]|= !col[i] and col_und[i][1] and col_und[1][2]-col_und[i][2]>0;

        dfs2(1,1);

        ll ans= 0;

        for( int i=1;i<=n;i++ )
            ans= ( ans+total[i]-total_kharap[i]+mod )%mod;

        printf("%lld\n", ans);

        clean(n);
    }
}
