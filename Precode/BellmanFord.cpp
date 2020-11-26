
struct edge
{
    int u,v,cost;
};

vector <edge> edges[100000];
int dist[100000];

int cnt=-1;
int n;
cin>>n
   for(int i=0; i<n; i++)
{
    int p,q,w;
    cin>>p>>q>>w;
    cnt++;
    edges[cnt].u=p;
    edges[cnt].v=q;
    edges[cnt].cost=w;
}

memset(dist, 0x3f , sizeof(dist));

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<=cnt;j++)
        {
            if( dist[ edges[j].u ] + edges[j].cost  < dist[ edges[j].v ])
                dist[ edges[j].v ]=  dist[ edges[j].u ] + edges[j].cost;
        }
    }

///Repeat this once to find if there's a negative weight cycle
