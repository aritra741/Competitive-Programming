#include <bits/stdc++.h>
#define mx 50007
using namespace std;

vector<int> adj[mx];
map<int,int> mp;
map<int,int> ::iterator it;
bool vis[mx];
int lvl[mx];

void bfs( int x )
{
    vis[x]= 1;
    lvl[x]= 1;
    mp[1]++;

    queue<int> q;
    q.push(x);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        vis[u]= 1;

        for(int i=0;i<adj[u].size();i++)
        {
            int v= adj[u][i];

            if(vis[v])
                continue;

            lvl[v]= lvl[u]+1;
            mp[lvl[v]]++;
            q.push(v);
        }
    }
}

int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=1;i<n;i++)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    bfs(1);

    ll ans= 0;

    for(it=mp.begin();it!=mp.end();it++)
    {
        ans+=
    }
}
