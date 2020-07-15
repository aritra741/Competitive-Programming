#include <bits/stdc++.h>
using namespace std;

int par[510];
vector<int> adj[510];
int ans,x;
int dist[550];

void bfs( int x )
{
    queue<int> q;
    q.push(x);
    dist[x]= 0;
    par[x]= -1;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();
       // cout<<u<<" "<<x<<" "<<ans<<endl;
        for(int i=0; i<adj[u].size(); i++)
        {
            int v= adj[u][i];

            if(par[u]==v)
                continue;
          //  cout<<v<<" "<<x<<endl;
            if( dist[v]!=-1  )
                ans= min( ans, dist[u]+dist[v]+1 );

            if( dist[v]==-1 )
            {
                par[v]= u;
                dist[v]= dist[u]+1;
                q.push( v );
            }
        }
    }

}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        memset(par,-1,sizeof(par));

        int n,m;
        scanf("%d %d", &n, &m);

        while(m--)
        {
            int p,q;
            scanf("%d %d", &p, &q);

            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        ans= 1e9;

        for(int i=0; i<n; i++)
        {
            memset(dist,-1,sizeof(dist));
            x= i;
            bfs(i);
        }

        printf("Case %d: ", t);

        if( ans==1e9 )
            printf("impossible\n");
        else
            printf("%d\n", ans);

        for(int i=0; i<n; i++)
            adj[i].clear();
    }
}
