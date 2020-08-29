struct edge
{
    int to, rev, flow, w;
};
struct dinic
{
    int d[N], done[N], s, t;
    const int INF=2e9;
    vector<edge> g[N];
/// N equals to node_number
    void addedge(int u, int v, int w)
    {
        edge a= {v,(int)g[v].size(),0,w};
        edge b= {u,(int)g[u].size(),0,0};
/// If the graph has bidirectional edges
/// Capacity for the edge b will be equal to w
/// For directed, it is 0
        g[u].emplace_back(a);
        g[v].emplace_back(b);
    }
    bool bfs()
    {
        mem(d,-1);
        d[s]=0;
        queue<int>q;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto &e: g[u])
            {
                int v=e.to;
                if(d[v]==-1 && e.flow<e.w)
                {
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return d[t]!=-1;
    }
    int dfs(int u, int flow)
    {
        if(u==t)
            return flow;
        for(int &i=done[u]; i<(int)g[u].size(); i++)
        {
            edge &e=g[u][i];
            if(e.w<=e.flow)
                continue;
            int v=e.to;
            if(d[v]==d[u]+1)
            {
                int nw=dfs(v,min(flow,e.w-e.flow));
                if(nw>0)
                {
                    e.flow+=nw;
                    g[v][e.rev].flow-=nw;
                    return nw;
                }
            }
        }
        return 0;
    }
    int max_flow(int _s, int _t)
    {
        s=_s;
        t=_t;
        int flow=0;
        while(bfs())
        {
            mem(done,0);
            while(int nw=dfs(s,INF))
                flow+=nw;
        }
        return flow;
    }
};

double dist( int x1, int y1, int x2, int y2 )
{
    return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
}

double xx[107], yy[107];
int nn[107], mm[107];

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int n;
        double d;
        scanf("%d %lf", &n, &d);

        int tot= 0;

        for( int i=0;i<n;i++ )
            scanf("%lf %lf %d %d", &xx[i], &yy[i], &nn[i], &mm[i]), tot+= nn[i];

        for( int i=0;i<n;i++ )
        {
            dinic flow;

            for( int j=0;j<n;j++ )
                flow.addedge( n, i, nn[i] )

            for( int j=0;j<n;j++ )
                for( int k=0;k<n;k++ )
                    if( j!=k and dist( xx[j], yy[j], xx[k], yy[k] ) )
                        flow.addedge( j,k );

            if( flow.max_flow()==tot )
        }
    }
}
