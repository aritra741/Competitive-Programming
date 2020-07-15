#include <bits/stdc++.h>
#define mx 200007
using namespace std;

bool vis[mx];
vector<int> adj[mx];
bool invalid;

void dfs(int u)
{
    vis[u]= 1;

    int sz= adj[u].size();

    if(sz!=2)
        invalid= 1;

    for(int i=0; i<sz; i++)
        if(!vis[ adj[u][i] ])
            dfs( adj[u][i] );
}

int main()
{
    int n,m;
    cin>>n>>m;

    while(m--)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    int cnt= 0;

    for(int i=1; i<=n; i++)
    {
        invalid= 0;

        if( vis[i] )
            continue;

        dfs(i);

        if(!invalid)
            cnt++;
    }

    cout<<cnt<<endl;

}
