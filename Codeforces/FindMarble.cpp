#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool vis[100005];
int lvl[100005];
vector <int> adj[100005];
queue<int> q;

int main()
{
    int n,s,t;
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        adj[i].push_back(p);
    }

    lvl[s]=0;
    q.push(s);
    bool found=0;

    while(!q.empty())
    {
        if(found)
            break;
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            if(found)
                break;
            int v=adj[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                if(v!=u)
                    lvl[v]=lvl[u]+1;
                if(v==t)
                    found=1;
                q.push(v);
            }
        }

        vis[u]=1;
    }

    if(found or s==t)
        cout<<lvl[t]<<endl;
    else
        cout<<"-1"<<endl;

}
