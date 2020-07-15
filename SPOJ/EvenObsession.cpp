#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair< int, pii >
#define inf 1e18
using namespace std;

ll dist[10007][2];          /// 0 for even, 1 for odd
vector<pii> adj[10007];

int main()
{
    int n,v;

    while( scanf("%d %d", &n, &v)==2 )
    {
        for( int i=0;i<=n;i++ )
            dist[i][0]= dist[i][1]= inf;
        for( int i=0;i<v;i++ )
        {
            int p,q,w;
            scanf("%d %d %d", &p, &q, &w);

            adj[p].push_back( pii( q,w ) );
            adj[q].push_back( pii( p,w ) );
        }

        dist[1][0]= 0;
        priority_queue< piii, vector<piii>, greater<piii> > pq;
        pq.push( piii( 0, pii( 1, 0 ) ) );

        int c= 0;
        while( !pq.empty() )
        {
            ll d= pq.top().first;
            int u= pq.top().second.first;
            int state= pq.top().second.second;
            pq.pop();

            if( d>dist[u][state] )
                continue;

            for( int i=0;i<adj[u].size();i++ )
            {
                int v= adj[u][i].first;
                ll w= adj[u][i].second;

                if( dist[v][!state]>dist[u][state]+w )
                {
                    dist[v][!state]= dist[u][state]+w;
                    pq.push( piii( dist[v][!state], pii( v, !state ) ) );
                }
            }
        }

        if( fabs((double)dist[n][0]-inf)<=100 )
            printf("-1\n");
        else
            printf("%lld\n", dist[n][0]);

        for( int i=0;i<=n;i++ )
            adj[i].clear();
    }
}


