#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,cost;
};

vector <edge> edges(400007);
int dist[210];

int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; t++)
    {
        getchar();
        int n;
        cout<<"Case "<<t<<":"<<endl;
        cin>>n;
        int busy[n+1];
        for(int i=1; i<=n; i++)
            cin>>busy[i];
        int roads;
        cin>>roads;
        int p,q;
        int cnt=-1;
        for(int i=0; i<roads; i++)
        {
            cin>>p>>q;
            cnt++;
            edges[cnt].u=p;
            edges[cnt].v=q;
            edges[cnt].cost=pow( (busy[q]-busy[p]), 3 );
        }

        memset(dist, 0x3f, sizeof(dist));
        dist[1]=0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<=cnt; j++)
            {
                if( dist[ edges[j].u ] + edges[j].cost  < dist[ edges[j].v ])
                    dist[ edges[j].v ]=  dist[ edges[j].u ] + edges[j].cost;
            }
        }

        bool valid=1;
        for(int j=0; j<=cnt; j++)
            {
                if( dist[ edges[j].u ] + edges[j].cost  < dist[ edges[j].v ])
                    {
                        dist[ edges[j].v ]=1000000009;
                    }
            }

        int qu;
        cin>>qu;
        for(int i=0;i<qu;i++)
        {
            int dest;
            cin>>dest;
            if(!valid || dist[dest]<3 || dist[dest]>1000000000){
                cout<<"?"<<endl;
                continue;
        }
            cout<<dist[dest]<<endl;
        }
    }
}
