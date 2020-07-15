#include<bits/stdc++.h>
using namespace std;

int arr[307], ans[307];
char mat[307][307];

vector<int>adj[307];
vector<int>idx,val;
bool vis[307];

void dfs( int u )
{
    idx.push_back(u);
    val.push_back( arr[u] );

    vis[u]= 1;

    for( auto v: adj[u] )
        if( !vis[v] )
            dfs(v);
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
        cin>>arr[i];

    for( int i=1;i<=n;i++ )
        for( int j=1;j<=n;j++ )
        {
            cin>> mat[i][j];
            if( mat[i][j]=='1' )
                adj[i].push_back(j);
        }

    for( int i=1;i<=n;i++ )
    {
        if( vis[i] )
            continue;

        idx.clear();
        val.clear();

        dfs(i);

        sort( val.begin(), val.end() );
        sort( idx.begin(), idx.end() );

        int j= 0;

        for( auto x: idx )
            ans[x]= val[j++];
    }

    for( int i=1;i<=n;i++ )
        cout<< ans[i] <<" ";
}
