#include <bits/stdc++.h>
#define ll long long
#define mod 100000110059LL
#define mx 500007
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

bool ase[mx];
bool vis[mx];
ll hit[mx];
int idx[mx];
int dist[mx];
std::vector<int> adj[mx];
map<int,bool>inqueue;

void bfs( int x )
{
    hit[x]= 1;
    queue<pii>q;
    q.push(pii(x,1));
    inqueue[x]= 1;
    dist[x]= 0;

    while(!q.empty())
    {
        int u= q.front().ff;
        int gelo= q.front().ss;

        q.pop();

        for( auto v: adj[u] )
        {
            if( ase[v] and gelo+1<idx[v] )
                continue;

            if( !inqueue[v] or dist[v]<=dist[u] )
            {
                hit[v]= (hit[u])%mod;
                dist[v]= dist[u]+1;
                int ekhon= gelo+ase[v];
                q.push(pii(v,ekhon));
                vis[v]= 1;
                inqueue[v]= 1;
            }

            else if( inqueue[v] and dist[v]==dist[u]+1 )
                hit[v]= (hit[v]+hit[u])%mod;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,x;
    cin>>n>>m>>x;

    for( int i=0;i<m;i++ )
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    int y;
    int fir= 0;

    for( int i=0;i<x;i++ )
    {
        cin>>y;

        if(!fir)
            fir= y;

        ase[y]= 1;
        idx[y]= i+1;
    }

    for( int i=1;i<=n;i++ )
        dist[i]= 2e9;

    bfs(fir);

    if( dist[y]>mx )
        cout<<"-1\n";
    else
        cout<<dist[y]<<" "<<hit[y]<<"\n";
}