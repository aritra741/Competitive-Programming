#include<bits/stdc++.h>
#define mx 100007
using namespace std;

vector<int>adj[mx], white, black;
int col[mx], par[mx];
bool vis[mx];

bool bfs( int u )
{
    vis[u]= 1;
    col[u]= 1;
    white.push_back(u);
    queue<int>q;
    q.push(u);

    while(!q.empty())
    {
        u= q.front();
        q.pop();

        for( int i=0; i<adj[u].size(); i++ )
        {
            int v= adj[u][i];

            if(!col[v])
            {
                if(col[u]==1)
                    col[v]= 2, black.push_back(v);
                else
                    col[v]= 1, white.push_back(v);
                vis[v]= 1;
                q.push(v);
            }
            else if(col[u]==col[v])
                return 0;
        }
    }
    return 1;
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
    {
        if(!col[i])
            if(!bfs(i))
                return cout<<"-1", 0;
    }

    cout<<white.size()<<endl;

    for( auto x: white )
        cout<<x<<" ";
    cout<<endl;

    cout<<black.size()<<endl;

    for( auto x: black )
        cout<<x<<" ";
    cout<<endl;

}
