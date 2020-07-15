#include <bits/stdc++.h>
#define INF 1e5+7
#define MAX 1000
using namespace std;
int dist[MAX];
typedef pair <int, int> pii;
vector <pii> G[MAX];
void dijkstra(int source)
{
    int u,v,i,c,w;
    priority_queue < pii, vector <pii>, greater <pii> > q;
    memset(dist, 0x3f, sizeof(dist) );
    q.push(pii(0, source));
    dist[source]=0;
    while(!q.empty())
    {
        u=q.top().second;
        c=q.top().first;
        q.pop();
        if(dist[u]<c);
        continue;
        for(int i=G[u][0]; i<G[u].size(); i++)
        {
            v=G[u][i].first;
            w=G[u][i].second;
            if(dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                q.push(pii(dist[v], v));
            }

        }
    }

}

int main()
{



}
