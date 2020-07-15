#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

map <string, int> stToInt;
map <int, string> IntToSt;

vector<pii> adj[60];
bool vis[100];
bool inMST[100];
long long dist[100];
int parDist[100];


void dfs(int x)
{
    for(int i=0; i<adj[x].size(); i++)
        if(!vis[adj[x][i].first])
        {
            vis[adj[x][i].first]=1;
            dfs(adj[x][i].first);
        }
}

int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; t++)
    {
        getchar();
        int roads;
        cin>>roads;
        int cnt=1;
        for(int i=0; i<roads; i++)
        {
            string p,q;
            int w;
            cin>>p>>q>>w;
            if(!stToInt[p])
            {
                stToInt[p]=cnt++;
                IntToSt[cnt-1]=p;
            }
            if(!stToInt[q])
            {
                stToInt[q]=cnt++;
                IntToSt[cnt-1]=q;
            }

            adj[stToInt[p]].push_back( pii(stToInt[q],w));
            adj[stToInt[q]].push_back( pii(stToInt[p],w));

        }

        memset(vis,0, sizeof(vis));

        bool flag=0;

        for(int i=1; i<cnt; i++)
        {
            if(!vis[i] and i!=1)
            {
                flag=1;
                break;
            }
            vis[i]=1;
            dfs(i);
        }

        if(flag)
        {
            cout<<"Case "<<t<<": Impossible"<<endl;
            stToInt.clear();
            IntToSt.clear();
            for(int i=1; i<cnt; i++)
                adj[i].clear();
            continue;
        }

        memset(dist, 0x3f, sizeof(dist));
        memset(inMST, false, sizeof(inMST));

        dist[1]=0;

        priority_queue<pii, vector<pii>, greater<pii> > pq;

        pq.push(pii(0,1));
        long long total=0;

        while(!pq.empty())
        {
            int u=pq.top().second;
            if(!inMST[u])
                total+=dist[u];
            inMST[u]=true;

            pq.pop();

            for(int i=0; i<adj[u].size(); i++)
            {
                int v=adj[u][i].first;
                int cost=adj[u][i].second;
                if( (cost < dist[v]) and (!inMST[v]) )
                {
                    dist[v]=cost;
                    pq.push(pii( dist[v], v ));
                }
            }
        }

        cout<<"Case "<<t<<": "<<total<<endl;

        stToInt.clear();
        IntToSt.clear();
        for(int i=1; i<cnt; i++)
            adj[i].clear();


    }
}
