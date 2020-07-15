#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

struct edge
{
    int u,v,w;
};

bool operator > ( edge a, edge b )
{
    return a.w>b.w;
}

bool operator == ( edge a, edge b )
{
    return a.w==b.w;
}

vector<edge> lst;
vector<pii> adj[100007];
priority_queue<pii, vector<pii>, greater<pii> > pq;
int dist[100007];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset( dist, 0x3f, sizeof(dist) );

    int n,m,s;
    cin>>n>>m>>s;

    for( int i=0;i<m;i++ )
    {
        edge e1;
        cin>>e1.u>>e1.v>>e1.w;

        adj[e1.u].push_back( pii(e1.v,e1.w) );
        adj[e1.v].push_back( pii(e1.u,e1.w) );
        lst.push_back( e1 );
    }

    int l;
    cin>>l;

    dist[s]= 0;
    pq.push( pii( 0,s ) );

    while( !pq.empty() )
    {
        pii p= pq.top();
        pq.pop();

        int u= p.second;
        int c= p.first;

        if( dist[u]<c )
            continue;

        for( int i=0;i<adj[u].size();i++ )
        {
            int vv= adj[u][i].first;
            int cc= adj[u][i].second;

            if( dist[vv]<dist[u]+cc )
                continue;

            dist[vv]= cc+dist[u];

            pq.push( pii( dist[vv], vv ) );
        }
    }

    int ans= 0;

    for( int i=0;i<n;i++ )
        if( dist[i+1]==l )
            ans++;

    for( int i=0;i<m;i++ )
    {
        edge e= lst[i];
        int u= e.u;
        int v= e.v;
        int w= e.w;

        if( dist[u]<l and l-dist[u]<w and w-(l-dist[u])+dist[v]>l )     /// the point is closer through u
            ans++;
        if( dist[v]<l and l-dist[v]<w and w-(l-dist[v])+dist[u]>l )     /// the point is closer through v
            ans++;
        if( dist[u]<l and dist[v]<l and dist[u]+dist[v]+w==2*l )        ///  equidistant
            ans++;
    }

    cout<< ans <<endl;
}
