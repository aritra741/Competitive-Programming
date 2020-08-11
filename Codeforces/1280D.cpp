#include<bits/stdc++.h>
#define mx 2007
using namespace std;

vector<int>adj[mx];
int arr[mx], ans[mx];
int n;

int boro;

int koyta( int u, int val )
{
    int ret= 0;
    boro= max( boro, ans[u] );

    if(ans[u]>val)
        ret++;

    for( auto v: adj[u] )
        ret+= koyta( v, val );

    return ret;
}

void dfs( int u )
{
    ij
}

int main()
{
    cin>>n;

    for( int i=1;i<n;i++ )
    {
        int p,v;
        cin>>p>>v;

        adj[p].push_back(i);
        arr[i]= v;
    }

    for( int i=1;i<=n;i++ )
        ans[i]= 1;
}

