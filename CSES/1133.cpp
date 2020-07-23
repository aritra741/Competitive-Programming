#include<bits/stdc++.h>
#define mx 200007
#define ll long long
using namespace std;

int n;
vector<int>adj[mx];
ll niche[mx], upore[mx], sub[mx], nichetot[mx];

void dfs1( int u, int p )
{
    sub[u]= 1;
    for( auto v: adj[u] )
    {
        if( v==p )
            continue;

        dfs1( v, u );
        niche[u]+= niche[v]+sub[v];
        nichetot[u]+= niche[v];
        sub[u]+= sub[v];
    }
}

void dfs2( int u, int p )
{
    for( auto v: adj[u] )
    {
        if( p==v )
            continue;

        upore[v]= (upore[u]+( n-sub[u]+1 ))+ (nichetot[u]-niche[v])+( sub[u]-sub[v]-1 )*2 ;
        dfs2( v, u );
    }
}

int main()
{
    cin>>n;

    for( int i=1;i<n;i++ )
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1,1);
    dfs2(1,1);

    for( int i=1;i<=n;i++ )
        cout<< upore[i]+niche[i] <<" ";
}
