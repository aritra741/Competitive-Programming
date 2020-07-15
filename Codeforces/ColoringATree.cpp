#include <bits/stdc++.h>
#define mx 10005
using namespace std;

int par[mx], col[mx];
bool vis[mx];
vector<int> adj[mx];

void dfs( int x, int y )
{
    vis[x]= 1;
    for(int i=0;i<adj[x].size();i++)
    {
        int v= adj[x][i];

        if(v==y or vis[v])
            continue;

        par[v]= x;
        dfs(v,x);
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i=2;i<=n;i++)
    {
        int p;
        cin>>p;

        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;

        col[i]= c;
    }

    dfs(1, 1);
    int cnt= 1;

    for(int i=2;i<=n;i++)
        if( col[ i ]!= col[ par[i] ] )
            cnt++;

    cout<< cnt <<endl;

}
