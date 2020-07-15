#include <bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

vector<int> adj[mx];
bool vis[mx];
int ans;

int dfs(int u)
{
    vis[u]= 1;
    int sz= adj[u].size();
    int tot= 1;

    for(int i=0; i<sz; i++)
    {
        int v= adj[u][i];
        if(vis[v])
            continue;
        int cnt= dfs( v );

        if( cnt%2==0)
            ans++;
        else
            tot+=cnt;
    }

    return tot;
}

int main()
{
    int n;
    cin>>n;
    int p,q;
    for(int i=1; i<n; i++)
    {
        cin>>p>>q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    if(n%2==1)
        cout<<"-1";
    else
    {
        dfs(1);

        cout<< ans <<endl;
    }
}
