#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main()
{
    int tc,p,q,w;
    cin>>tc;
    while(tc--)
    {

    int nodes,source,mxcost,edges;
    scanf("%d %d %d %d", &nodes, &source, &mxcost, &edges);
    int dist[nodes+1];
    memset(dist, 0x3f, sizeof(dist));
    vector < pii > G[nodes+1];

    for(int i=0;i<edges;i++)
    {
        cin>>p>>q>>w;
        G[q].push_back(pii(p,w));
    }

    priority_queue <pii, vector<pii>, greater<pii> > qu;
    qu.push(pii(0, source));
    dist[source]=0;
    while(!qu.empty())
    {

        int u=qu.top().second;
        int c=qu.top().first;
        qu.pop();
        if(dist[u]< c)
            continue;

        for(int i=0;i<G[u].size();i++)
        {

            if(dist[G[u][i].first]> c+G[u][i].second)
            {
                dist[G[u][i].first]= c+G[u][i].second;
                qu.push(pii(dist[G[u][i].first], G[u][i].first));
            }
        }

    }
    int cnt=0;
    for(int i=1;i<=nodes;i++)
        if(dist[i]<=mxcost)
           {
            cnt++;}
    cout<<cnt<<endl;
    if(tc)
        cout<<endl;
}
}
