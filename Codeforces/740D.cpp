#include<bits/stdc++.h>
#define mx 200007
using namespace std;

vector<int>adj[mx], w[mx];
int ans[mx], arr[mx];

int dfs( int u )
{
    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];
        if( w[u][i]<=arr[v] )
            ans[u]++;
        ans[u]+= dfs(v);
    }

    return ans[u];
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
        cin>>arr[i];

    for( int i=2;i<=n;i++ )
    {
        int p,c;
        cin>>p>>c;

        adj[p].push_back(i);
        w[p].push_back(c);
    }

    int pp= dfs(1);

    for( int i=1;i<=n;i++ )
        cout<< ans[i] <<" ";
}
