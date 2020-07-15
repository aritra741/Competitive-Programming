#include<bits/stdc++.h>
#define mx 100007
using namespace std;

int ase[mx], lagbe[mx];
bool flip[mx];
int par[mx];
vector<int>adj[mx], v;

void dfs( int u, int p )
{
    if( par[p]!=p and flip[ par[p] ] )
        ase[u]^= 1;

    if( ase[u]!=lagbe[u] )
    {
        v.push_back(u);
        if( par[p]!=p )
            flip[u]= flip[ par[p] ]^1;
        else
            flip[u]= 1;
    }
    else if( par[p]!=p )
        flip[u]= flip[ par[p] ];

    for( auto v: adj[u] )
    {
        if( v==p )
            continue;

        par[v]= u;
        dfs( v, u );
    }
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<n;i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    for( int i=1;i<=n;i++ )
        cin>> ase[i];
    for( int i=1;i<=n;i++ )
        cin>> lagbe[i];

    dfs( 1, 1 );

    cout<< v.size() <<endl;

    for( auto x: v )
        cout<<x<<"\n";
}
