#include <bits/stdc++.h>
using namespace std;

set <int> color[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    int col[n+1];
    vector <int> adj[n+1];
    for(int i=1;i<=n;i++)
        cin>>col[i];
    int p,q;
    for(int i=0;i<m;i++)
    {
        cin>>p>>q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    int ans=-1;
    int node,out;
    for(int i=1;i<=n;i++)
    {
        int sz=adj[i].size();
        for(int j=0;j<sz;j++)
            {
                if(col[i]!=col[adj[i][j]])
                    color[col[i]].insert(col[adj[i][j]]);
            }
        int stsz=color[col[i]].size();
        if(stsz>ans)
        {
            ans=stsz;
            out=col[i];
        }
        else if(stsz==ans)
        {
            out=min(out, col[i]);
        }
    }

    cout<<out;
}
