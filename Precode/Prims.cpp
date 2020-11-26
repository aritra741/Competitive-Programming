#define pii pair <int, int>
#define INF 1e15

vector <pii> adj[10000];

vector <int> dist(10000, INF)

vector <bool> inMST(10000, 0);

priority_queue< int , vector<int>, greater <int> > pq;

///Take input
cin>>p>>q;
adj[p].push_back( pii(q,w) );

dist[0]=0;
pq.push( pii( 0,0 ) );

while(!pq.empty())
{
    int u=pq.top().second;
    pq.pop();

    inMST=true;

    for(int i=0;i<adj[u].size();i++)
    {
        int c=adj[u][i].second;
        int v=adj[u][i].first;
        if(c < dist[v]  && !inMST[v])
        {
            dist[v]= c ;
            pq.push( pii(dist[v], v) );
        }
    }
}
