#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

vector<pii> adj[300007];
vector<int> ans;
bool vis[300007], del[300007];
int par[300007], dist[300007];
queue<int> q;

int main()
{
    int n,k,d;
    cin>>n>>k>>d;

    for(int i=0; i<k; i++)
    {
        int p;
        scanf("%d", &p);

        q.push ( p );
        vis[p]= 1;
    }

    for(int i=0; i<n-1; i++)
    {
        int p,q;
        scanf("%d %d", &p, &q);

        adj[p].push_back( pii(q, i+1) );
        adj[q].push_back( pii(p, i+1) );
    }

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        if( dist[u]>d )
            continue;

        for( int i=0; i<adj[u].size(); i++)
        {
            pii v;
            v.f= adj[u][i].f;
            v.s= adj[u][i].s;

            if( del[v.s] )
                continue;

            if( v.f==par[u] or par[v.f]==u )
                continue;
            if( vis[v.f] )
                del[v.s]= 1,
                ans.push_back( v.s );
            else
            {
                vis[v.f]= 1;
                par[v.f]= u;
                dist[v.f]= dist[u]+1;

                q.push( v.f );
            }
        }
    }

    printf("%d\n", ans.size());

    for(int i=0; i<ans.size(); i++)
        printf("%d ", ans[i]);
}
