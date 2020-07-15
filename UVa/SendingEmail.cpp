#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
typedef pair<int,int> pii;
int main()
{
    int tc;
    cin>>tc;
    int num,m,s,t;
    for(int i=1; i<=tc; i++)
    {
        cin>>num>>m>>s>>t;
        if(m==0)
        {
            cout<<"Case #"<<i<<": unreachable"<<endl;
            continue;
        }
        vector <pii> G[num];
        int dist[num];
        for(int mx=0; mx<num; mx++)
            dist[mx]=MAX;
        int p,q,w;
        for(int j=0; j<m; j++)
        {
            cin>>p>>q>>w;
            G[p].push_back(pii(q,w));
            G[q].push_back(pii(p,w));
        }
        dist[s]=0;
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        pq.push(pii(0, s));
        while(!pq.empty())
        {

            int u=pq.top().second;
            int w=pq.top().first;
            pq.pop();
            if(dist[u]<w)
                continue;
            for(int it=0; it<G[u].size(); it++)
            {
                int nd=G[u][it].first;
                int c= G[u][it].second;
                if(dist[nd]>c+w)
                {

                    dist[nd]=c+w;
                    pq.push(pii(dist[nd], nd));
                }

            }
        }
        if(dist[t]==MAX)
            cout<<"Case #"<<i<<": unreachable"<<endl;
        else
            cout<<"Case #"<<i<<": "<<dist[t]<<endl;
        for(int cl=0; cl<num; cl++)
            G[cl].clear();
    }
}
