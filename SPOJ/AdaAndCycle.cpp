#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

int dist[2010];
vector<int> adj[2010];

bool bfs( int x )
{
    queue<int>q;
    q.push(x);

    memset( dist, -1, sizeof(dist) );
    dist[x]= 0;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for( int i=0; i<adj[u].size(); i++ )
        {
            int v= adj[u][i];

            if( dist[v]==-1 )
            {
                dist[v]= dist[u]+1;
                q.push(v);
            }

            else if( dist[v]!=-1 and v==x )
            {
                dist[v]= dist[u]+1;
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            int p;
            scanf("%d", &p);

            if(p)
                adj[i].push_back(j);
        }

    for( int i=0; i<n; i++ )
    {
        if( bfs(i) )
            printf("%d\n", dist[i]);
        else
            printf("NO WAY\n");
    }
}
