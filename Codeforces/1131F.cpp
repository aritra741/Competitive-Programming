#include<bits/stdc++.h>
#define mx 150007
using namespace std;

int par[mx];
vector<int>vv[mx];

int Find( int u )
{
    if( par[u]==u )
        return u;
    return par[u]= Find(par[u]);
}

void unite( int u, int v )
{
    int paru= Find(u);
    int parv= Find(v);

    if( vv[paru].size()>vv[parv].size() )
    {
        par[parv]= paru;
        for( auto x: vv[parv] )
            vv[paru].push_back( x );
    }
    else
    {
        par[paru]= parv;
        for( auto x: vv[paru] )
            vv[parv].push_back( x );
    }
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
        par[i]= i, vv[i].push_back(i);

    for( int i=1;i<n;i++ )
    {
        int x,y;
        cin>>x>>y;

        unite(x,y);
    }

    for( auto x: vv[Find(1)] )
        cout<<x<<" ";
}
