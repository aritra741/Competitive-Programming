#include<bits/stdc++.h>
#define mx 200007
using namespace std;

vector<int>adj[mx];
set<int>st[mx];
int col[mx], ans[mx];

void dfs( int u, int p )
{
    st[u].insert( col[u] );

    for( auto v: adj[u] )
    {
        if(v==p)
            continue;

        dfs( v,u );

        if( st[u].size()<st[v].size() )
            st[u].swap( st[v] );

        for( auto x: st[v] )
            st[u].insert(x);
    }

    ans[u]= st[u].size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
        cin>>col[i];

    for( int i=1;i<n;i++ )
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs( 1,1 );

    for( int i=1;i<=n;i++ )
        cout<< ans[i] <<" ";
}
