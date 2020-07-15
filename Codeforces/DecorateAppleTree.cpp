#include <bits/stdc++.h>
#define mx 100007
using namespace std;

map<int, int> mp;
map<int, int> ::iterator it;
vector<int> adj[mx];
bool vis[mx];

int dfs( int u )
{
    vis[u]= 1;
    int sz= adj[u].size();

    if(!sz)
    {
        mp[1]++;
        return 1;
    }

    int cnt= 0;

    for(int i=0;i<sz;i++)
    {
        int v= adj[u][i];

        if(vis[v])
            continue;

        cnt+= dfs(v);
        vis[v]= 1;
    }

    mp[cnt]++;

    return cnt;
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
    }

    dfs(1);

    for(it=mp.begin();it!=mp.end();it++)
    {
        int cnt= it->second;
        int col= it->first;

        for(int i=0;i<cnt;i++)
            cout<<col<<" ";
    }
}
