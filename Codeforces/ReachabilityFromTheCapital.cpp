#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;

int vis[5010];
vector <int> adj[5010];
int reach[5010];

void traverse1(int x, int src)
{
    reach[src]++;
   // cout<<src<<endl;
    for(int i=0;i<adj[x].size();i++)
    {
        int u=adj[x][i];
            if(vis[u]==0)
            {
                vis[u]=2;
                traverse1(u, src);
            }
    }
}
void traverse2(int x)
{
    for(int i=0;i<adj[x].size();i++)
    {
        int u=adj[x][i];
            if(!vis[u])
            {
                vis[u]=1;
                traverse2(u);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,s;
    cin>>n>>m>>s;

    priority_queue <pii> pq;

    for(int i=0;i<m;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
    }
    vis[s]=1;
    traverse2(s);
    for(int j=1;j<=n;j++){
        if(vis[j]!=1){
        vis[j]=2;
        traverse1(j, j);
        pq.push( pii(reach[j], j) );
        //cout<<j<<" "<<reach[j]<<endl;
        for(int i=1;i<=n;i++)
            if(vis[i]==2)
                vis[i]=0;
        }

    }

    //cout<<pq.top().second;

    int cnt=0;

    while(!pq.empty())
    {
        int x=pq.top().second;
        pq.pop();
        if(vis[x]==1)
            continue;
        cnt++;
        for(int i=0;i<adj[x].size();i++)
        {
            int u=adj[x][i];
            if(vis[u]==0)
            {
                vis[u]=1;
                traverse2(u);
            }
        }
    }
    cout<<cnt<<endl;

}
