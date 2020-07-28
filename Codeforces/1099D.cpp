#include<bits/stdc++.h>
#define inf 1000000000
#define ll long long
#define mx 100007
using namespace std;

vector<int>adj[mx];
int h[mx], a[mx];
bool f;
ll ans;

void dfs( int u, int now )
{
    if(f)
        return;

    if( h[u]>-1 )
    {
        a[u]= h[u]-now;

        if( a[u]<0 )
        {
            f= 1;
            return;
        }
    }
    else
    {
        a[u]= inf;

        for( auto v: adj[u] )
            a[u]= min( a[u], h[v]-now );

        if( a[u]==inf )
            a[u]= 0;

        if( a[u]<0 )
        {
            f= 1;
            return;
        }
    }

    for( auto v: adj[u] )
        dfs( v, now+a[u] );

    ans+= a[u];
}

int main()
{
    int n;
    cin>>n;

    for( int i=2;i<=n;i++ )
    {
        int p;
        cin>>p;

        adj[p].push_back(i);
    }

    for( int i=1;i<=n;i++ )
        cin>> h[i];

    dfs( 1, 0 );

    if( f )
        return cout<<"-1", 0;

    cout<< ans <<endl;
}
