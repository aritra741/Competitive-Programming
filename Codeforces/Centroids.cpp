#include <bits/stdc++.h>
#define MX 400007
using namespace std;

vector<int> adj[MX];
bool vis[MX];
int sub[MX], par[MX], cent, n;

int centroid( int u, int p )
{
    sub[u]= 1;
    bool Centroid= true;

    for( int i=0; i<adj[u].size(); i++ )
    {
        int v= adj[u][i];

        if( v==p )
            continue;

        int now= centroid( v, u );

        if( now>n/2 )
            Centroid= false;
        sub[u]+= now;
    }

    if( n-sub[u]>n/2 )          /// The rest
        Centroid= false;

    if( Centroid )
        cent= u;
    return sub[u];
}

void dfs( int u, int p )        /// Marking the centroid as root
{                               /// and keeping track of the subtree each node belongs to
    sub[u]= 1;
    if( p!=-1 )
    {
        for( int i=0; i<adj[u].size(); i++ )
        {
            int v= adj[u][i];

            if( v==p )
                continue;

            par[v]= par[u];
            dfs(v,u);
            sub[u]+= sub[v];
        }
    }

    else
    {
        for( int i=0; i<adj[u].size(); i++ )
        {
            int v= adj[u][i];

            if( v==p )
                continue;

            par[v]= v;
            dfs(v,u);
            sub[u]+= sub[v];
        }
    }
}

int main()
{
    cin>>n;

    for( int i=1; i<n; i++ )
    {
        int p,q;
        scanf("%d %d", &p, &q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    centroid(1,-1);
    par[cent]= -1;
    dfs(cent,-1);

    int mx= -1, scnd= -1, idx= 0, secidx= 0;

    for( int i=0;i<adj[cent].size();i++ )
    {
        int v= adj[cent][i];

        if( sub[v]>mx )
            scnd= mx, mx= sub[v], idx= v;           ///Update scnd too
        else if( sub[v]>scnd )
            scnd= sub[v], secidx= v;
    }

    for( int i=1;i<=n;i++ )
    {
        if( i==cent )
        {
            printf("1 ");
            continue;
        }
        int now= -1;

        if( par[i]==idx )
            now= max( scnd, sub[idx]-sub[i] );
        else
            now= mx;

        now= n- now-sub[i];

        printf("%d ", !(now> n/2));
    }

}
