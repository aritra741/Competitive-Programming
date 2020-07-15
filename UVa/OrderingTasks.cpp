#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(1)
    {
        cin>>n>>m;
        if(!n & !m)
            break;
        int indegree[n+1];
        vector <int> adj[n+1];
        vector <int> t;

        memset(indegree, 0, sizeof(indegree));

        for(int i=0;i<m;i++)
            {
                int p,q;
                cin>>p>>q;
                adj[p].push_back(q);
                indegree[q]++;
            }

        queue<int> q;

        for(int i=1;i<=n;i++)
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty())
        {
            int u=q.front();
            t.push_back(u);
            q.pop();
            for(int i=0;i<adj[u].size();i++)
            {
                indegree[adj[u][i]]--;
                if(indegree[adj[u][i]]==0)
                    q.push(adj[u][i]);
            }
        }

        for(int i=0;i<t.size();i++)
            cout<<t[i]<<" ";
        cout<<endl;

    }
}
