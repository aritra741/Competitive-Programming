#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector <int> adj[n];
    for(int p=0;p<n;p++)
    {
        int m,l;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>l;
            adj[p].push_back(l);
        }
    }

    queue <int> q;
    bool vis[n];
    int lvl[n];

    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        int src;
        cin>>src;

        memset(vis, 0, sizeof(vis));
        memset(lvl, 0, sizeof(lvl));

        vis[src]=1;
        lvl[src]=0;
        map <int, int> level;
        q.push(src);
        int ans1=0,ans2=0;

        while(!q.empty())
        {

            int u=q.front();
            q.pop();
            int cnt=0;

            for(int k=0;k<adj[u].size();k++)
                {
                    if(vis[ adj[u][k] ]==0)
                    {
                        q.push( adj[u][k] );
                        vis[ adj[u][k] ]=1;
                        lvl[ adj[u][k] ]= lvl[u]+1;
                        level[lvl[u]+1]++;
                    }
                }
                if(level[lvl[u]+1]>ans1)
                {
                   // cout<<u<<" "<<lvl[u]<<endl;
                    ans1=level[lvl[u]+1];
                    ans2=lvl[u]+1;
                }
        }
        if(ans1==0)
            cout<<"0"<<endl;
        else
            cout<<ans1<<" "<<ans2<<endl;
    }

}
