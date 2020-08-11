#include<bits/stdc++.h>
#define ll long long
#define mx 200007
using namespace std;

ll a[mx], b[mx];
vector<int>adj[mx];
int ind[mx];
bool vis[mx], mark[mx];
vector<int>topo;

void dfs( int u )
{
    vis[u]= 1;
    for( auto v: adj[u] )
        if(!vis[v])
            dfs(v);

    topo.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for( int i=1; i<=n; i++ )
        cin>>a[i];
    for( int i=1; i<=n; i++ )
        cin>>b[i];

    for( int i=1; i<=n; i++ )
        if( b[i]!=-1 )
            adj[i].push_back(b[i]), ind[b[i]]++;

    for( int i=1; i<=n; i++ )
        if(!ind[i])
            dfs(i);

    reverse( topo.begin(), topo.end() );

    ll ans= 0;
    vector<int>v;

    for( auto x: topo )
        if( a[x]>=0 )
        {
            v.push_back(x);
            ans+= a[x];
            mark[x]= 1;

            if( adj[x].size() )
                a[ adj[x][0] ]+= a[x];
        }

    reverse( topo.begin(), topo.end() );

    for( auto x: topo )
        if( !mark[x] )
        {
            v.push_back(x);
            ans+= a[x];
            mark[x]= 1;

            if( adj[x].size() )
                a[ adj[x][0] ]+= a[x];
        }

    cout<< ans <<"\n";

    for( auto x: v )
        cout<<x<<" ";
}
