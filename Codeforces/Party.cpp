#include <bits/stdc++.h>
using namespace std;

vector <int> adj[2001];
int lvl[2001];


int main()
{
    int n;
    cin>>n;
    int par[n+1];
    par[0]=0;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        if(p==-1)
            par[i]=-1;
        else
        {
            adj[p].push_back(i);
            par[i]=p;
        }
    }
    int mx=1;
    for(int i=1;i<=n;i++)
    {
        if(par[i]==-1)
        {
            lvl[i]=1;
            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                mx=max(mx, lvl[u]);
                for(int j=0;j<adj[u].size();j++)
                {
                    lvl[ adj[u][j] ]=lvl[u]+1;
                    q.push( adj[u][j] );
                }
            }
        }
    }
    cout<<mx;


}
