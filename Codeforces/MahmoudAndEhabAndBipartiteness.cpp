#include <bits/stdc++.h>
#define MX 100007
#define ll long long
using namespace std;

vector<int> adj[MX];
int lvl[MX];
bool vis[MX];
int one= 0, two= 0;

void bfs( int u )
{
    lvl[u]= 1;
    queue<int> q;
    q.push(u);

    while(!q.empty())
    {
        int v= q.front();
        vis[v]= 1;
        if(lvl[v]&1)
            one++;
        else
            two++;
        q.pop();

        for(int i=0; i<adj[v].size(); i++)
        {
            int p= adj[v][i];

            if( vis[p] )
                continue;

            lvl[p]= lvl[v]+1;
            q.push(p);
        }
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    bfs(1);

    ll ans= one*two;
    ans-=n-1;

    cout<< ans <<endl;
}
