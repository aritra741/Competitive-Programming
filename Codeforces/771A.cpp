#include<bits/stdc++.h>
#define mx 150007
using namespace std;

vector<int>adj[mx], cc[mx];
int bel[mx];
bool vis[mx];
int cnt;

void bfs( int u )
{
    vis[u]= 1;
    queue<int>q;
    q.push(u);

    while(!q.empty())
    {
        u= q.front();
        cc[cnt].push_back(u);
        bel[u]= cnt;
        q.pop();

        for( int i=0; i<adj[u].size(); i++ )
        {
            int v= adj[u][i];

            if(!vis[v])
            {
                vis[v]= 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for( int i=0; i<m; i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    for( int i=1; i<=n; i++ )
        if(!vis[i])
            cnt++, bfs(i);

    for( int i=1;i<=n;i++ )
        if(adj[i].size())
            if( (int)cc[bel[i]].size()-1!=(int)adj[i].size() )
                return cout<<"NO\n", 0;

    cout<<"YES\n";
}

