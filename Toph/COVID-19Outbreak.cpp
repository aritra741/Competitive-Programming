#include<bits/stdc++.h>
#define mx 1000007
#define ll long long
using namespace std;

vector<int>adj[mx], cost[mx];
ll arr[mx];

ll dfs( int u, int pre )
{
    ll ret= arr[u];
    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];

        if(v==pre)
            continue;
        ll lim= cost[u][i];

        lim= min( lim, dfs( v, u ) );
        ret+= lim;
    }

    return ret;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for( int i=1;i<n;i++ )
    {
        int p,q,w;
        cin>>p>>q>>w;

        adj[p].push_back(q);
        adj[q].push_back(p);
        cost[p].push_back(w);
        cost[q].push_back(w);
    }

    for( int i=1;i<=n;i++ )
        cin>>arr[i];

    cout<< dfs(m,m) <<endl;
}

