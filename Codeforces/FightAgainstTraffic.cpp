#include <bits/stdc++.h>
using namespace std;

bool mat[1010][1010];
vector<int> adj[1010];
int sdis[1010], tdis[1010];
bool vis[1010];
int s,t;

void bfs1()
{
    queue<int> q;
    q.push(s);
    vis[s]= 1;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        int sz= adj[u].size();

        for(int i=0; i<sz; i++)
        {
            int v= adj[u][i];

            if(vis[v])
                continue;
            sdis[v]= sdis[u]+1;
            vis[v]= 1;
            q.push(v);
        }

    }
}

void bfs2()
{
    queue<int> q;
    q.push(t);
    vis[t]= 1;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        int sz= adj[u].size();

        for(int i=0; i<sz; i++)
        {
            int v= adj[u][i];

            if(vis[v])
                continue;
            tdis[v]= tdis[u]+1;
            vis[v]= 1;
            q.push(v);
        }

    }
}

int main()
{
    int n,m;
    cin>>n>>m>>s>>t;

    for(int i=0; i<m; i++)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);

        mat[p][q]= 1;
        mat[q][p]= 1;
    }

    bfs1();
    memset( vis,0,sizeof(vis) );
    bfs2();


    int dist= min( sdis[t], tdis[s] );
    int cnt= 0;

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
        {
            if( mat[i][j] )
                continue;
            if( (s==i and t==j) or (t==i and s==j) )
                continue;
            int mn= min( sdis[i]+tdis[j], sdis[j]+tdis[i] );
            mn++;

            if( mn>=dist )
                cnt++;
        }

    cout<< cnt <<endl;
}

