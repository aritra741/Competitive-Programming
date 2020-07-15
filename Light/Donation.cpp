#include <bits/stdc++.h>
#define pii pair <int, int>
#define ll long long
using namespace std;

int arr[100][100];
bool vis[110];
vector <pii> adj[110];
int dist[110];
bool inMST[110];

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
        long long total=0;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                cin>>arr[i][j];
               // cout<<"YES";
                if(i!=j and arr[i][j])
                    {
                        adj[i].push_back( pii(j, arr[i][j]) );
                        adj[j].push_back( pii(i, arr[i][j]) );
                    }
                total+=arr[i][j];
            }

        bool flag=0;
        memset(vis, 0 , sizeof(vis));

        for(int i=0; i<n; i++)
        {
            if(!vis[i] and i!=0)
            {
                flag=1;
                break;
            }
            vis[i]=1;
            dfs(i);
        }

        if(flag)
        {
            cout<<"Case "<<t<<": -1"<<endl;
            for(int i=0;i<n;i++)
                adj[i].clear();

            continue;
        }

        priority_queue <pii, vector<pii>, greater<pii> > pq;
        memset(dist, 0x3f, sizeof(dist));
        memset(inMST, false, sizeof(inMST));
        ll mst=0;

        dist[0]=0;
        pq.push(pii(0,0));

        while(!pq.empty())
        {
            int u=pq.top().second;
            int cost= pq.top().first;
            if(!inMST[u])
                mst+=dist[u];
            pq.pop();
            inMST[u]=true;

            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i].first;
                int weight=adj[u][i].second;

                if(weight < dist[v])
                {
                    dist[v]=weight;
                    pq.push( pii(dist[v], v) );
                }
            }
        }

        cout<<"Case "<<t<<": "<<total-mst<<endl;
        memset(dist, 0x3f, sizeof(dist));
        memset(inMST, false, sizeof(inMST));
         for(int i=0;i<n;i++)
                adj[i].clear();


    }
}
