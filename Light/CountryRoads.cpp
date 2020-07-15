#include <bits/stdc++.h>
#define pii pair<int, int>
#define INF 40000
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; t++)
    {
        getchar();

        printf("Case %d:\n", t);

        int n,m,p,q,w;
        scanf("%d %d", &n,&m);

        bool vis[n];
        memset(vis, 0, sizeof(vis));

        int dist[n];
        memset(dist, 0x3f, sizeof(dist));

        vector<pii> adj[n];

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d", &p, &q, &w);
            adj[p].push_back( pii(q,w) );
            adj[q].push_back( pii(p,w) );

        }

        int src;
        cin>>src;

        priority_queue<pii, vector <pii>, greater<pii> > pq;
        vis[src]=1;
        dist[src]=0;
        pq.push(pii(0,src));

        while(!pq.empty())
        {
            int node=pq.top().second;
            int cost=pq.top().first;

            pq.pop();

            if(cost > dist[node])
                continue;

            for(int i=0; i<adj[node].size(); i++)
            {

                int u= adj[node][i].first;
                int c= adj[node][i].second;

                if( max( c, cost  ) < dist[u] )
                {
                    dist[u]= max(c, cost);
                    pq.push( pii(dist[u], u) );
                    vis[u]=1;
                }
            }


        }
        for(int i=0; i<n; i++)
        {

            if(vis[i])
                printf("%d\n", dist[i]);
            else
                printf("Impossible\n");
        }
        getchar();
    }

}
