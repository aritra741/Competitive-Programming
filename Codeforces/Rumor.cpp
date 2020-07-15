#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define mx 100007
using namespace std;

vector <int> adj[mx];
pll cost[mx];
bool vis[mx];

void dfs( int u )
{
    vis[u]=1;

    int sz= adj[u].size();

    for(int i=0; i<sz; i++)
    {
        int v= adj[u][i];
        if(!vis[ v ])
            dfs(v);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        pll p;
        cin>>p.first;
        p.second= i;
        cost[i-1]= p;
    }

    sort( cost, cost+n );

    for(int i=0; i<m; i++)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    ll ans=0;

    for(int i=0; i<n; i++)
    {
        pll p= cost[i];

        int u= p.first;
        int v= p.second;

        if(!vis[v])
        {
            ans+=u;
            dfs(v);
        }
    }

    cout<< ans <<endl;


}
