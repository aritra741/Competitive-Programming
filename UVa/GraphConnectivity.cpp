#include <bits/stdc++.h>
using namespace std;

bool vis[30];
vector <int> adj[30];

void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        int u=adj[x][i];
        if(vis[u]==0)
            dfs(u);
    }
}

int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
      //  getchar();
        string s1;
        cin>>s1;
        getchar();
        int n=s1[0]-'A'+1;

        string s;
        while(getline(cin,s))
        {
            if(s[0]=='\0')
                break;
            int id1=s[0]-'A'+1;
            int id2=s[1]-'A'+1;
            adj[id1].push_back(id2);
            adj[id2].push_back(id1);


        }

        memset(vis, 0, sizeof(vis));
        int cnt=0;

        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
                cnt++;
            }
        }
        cout<<cnt<<endl;
        if(t!=tc)
            cout<<endl;

        for(int i=0;i<=26;i++)
            adj[i].clear();

    }
}
