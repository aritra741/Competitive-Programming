#include<bits/stdc++.h>
#define ll long long
#define mx 200007
#define inf 1000000000000000000
using namespace std;

vector<int>adj[mx];
int val[mx], lagbe[mx];
ll zl[mx], ol[mx], sub[mx], cost[mx];
ll ans;

void dfs( int u, int p )
{
    sub[u]++;
    if( val[u] )
    {
        if(!lagbe[u])
            zl[u]++;
    }
    else
    {
        if(lagbe[u])
            ol[u]++;
    }

    for( auto v: adj[u] )
    {
        if(v==p)
            continue;
        dfs(v,u);

        zl[u]+= zl[v];
        ol[u]+= ol[v];
        sub[u]+= sub[v];
    }
}

void rec( int u, int p, int mnval )
{
    if( val[u]!=lagbe[u] )
    {
        if( val[u] )
            zl[u]++;
        else
            ol[u]++;
    }

    int cc= min(cost[u],(ll)mnval);

    for( auto x: adj[u] )
    {
        if(x==p)
            continue;
        rec( x, u, cc );
        zl[u]+= zl[x];
        ol[u]+= ol[x];
    }

    int nibo= min( zl[u],ol[u] );
    ans+= nibo*1LL*cc*2LL;
    zl[u]-= nibo;
    ol[u]-= nibo;
}

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=1;i<=n;i++ )
        scanf("%lld %d %d", &cost[i], &val[i], &lagbe[i]);

    for( int i=1;i<n;i++ )
    {
        int p,q;
        scanf("%d %d", &p, &q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    dfs(1,1);

    if(zl[1]!=ol[1])
        return cout<<"-1\n", 0;

    memset( zl,0, sizeof(zl) );
    memset( ol,0, sizeof(ol) );

    rec( 1,1,cost[1] );

    printf("%lld\n", ans);
}
