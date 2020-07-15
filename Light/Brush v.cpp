#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> pii;
int main()
{
    int tc;
    cin>>tc;
    getchar();
    for(int i=1;i<=tc;i++)
    {
        priority_queue <pii, vector<pii>, greater<pii> > pq;

        int n,m,p,q,w;
        cin>>n>>m;
        if(m==0)
            cout<<"Case "<<i<<": Impossible"<<endl;
        else{
        int dist[n+1];
        for(int it=0;it<n;it++)
            dist[it]=100000;
        vector <pii> G[n+1];
        for(int j=0;j<m;j++)
        {
            cin>>p>>q>>w;
            G[q].push_back(pii(p,w));
            G[p].push_back(pii(q,w));

        }
        dist[1]=0;
        pq.push(pii(0, 1));
        while(!pq.empty())
        {

            int u=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            if(dist[u]<w)
                continue;
            for(int l=0;l<G[u].size();l++)
            {
                if(dist[G[u][l].first]>w+G[u][l].second)
                    {
                        dist[G[u][l].first]=w+G[u][l].second;
                        pq.push(pii(dist[G[u][l].first], G[u][l].first));
            }
        }
    }
    for(int cl=0;cl<=n;cl++)
        G[cl].clear();

    if(dist[n]>1000)
        cout<<"Case "<<i<<": Impossible"<<endl;
    else
    cout<<"Case "<<i<<": "<<dist[n]<<endl;
}}
}
