#include<bits/stdc++.h>
#define mx 100007
using namespace std;

vector<int>adj[mx];
int par[mx], col[mx];

int ans= 0;
bool f= 1;

void dfs( int u, bool dep )
{
    if(!f)
        return;
    if( par[u]!=u and dep )
    {
        if( col[u]<col[ par[ par[u] ] ] )
        {
            f= 0;
            return;
        }
    }

    for( auto v: adj[u] )
        dfs( v, dep^1 );
}

int main()
{
    int n;
    cin>>n;

    for( int i=2;i<=n;i++ )
    {
        int p;
        cin>>p;

        par[i]= p;
        adj[p].push_back(i);
    }

    for( int i=1;i<=n;i++ )
        cin>> col[i], ans= max( ans, col[i] );

    dfs(1,1);

    if(!f)
        cout<<"-1"<<endl;
    else
        cout<<ans<<endl;
}
