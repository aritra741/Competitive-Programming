#include <bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
using namespace std;

vector<pii> adj[100005];
bool vis[100005];
int ans;
bool flag=0;

void traverse(int x)
{
    int sz=adj[x].size();
    for(int i=0;i<sz;i++)
    {
        if(!vis[adj[x][i].first])
        {
            vis[adj[x][i].first]=1;
            if(adj[x][i].second==2)
                ans=adj[x][i].first;
            traverse(adj[x][i].first);
        }
    }

    if(!flag and ans)
    {
        outpu
    }
}

using namespace std;
int main()
{
    int n;
    cin>>n;
    int p,q,state;
    for(int i=1;i<n;i++)
        {
            cin>>p>>q>>state;
            adj[p].pb( pii(q,state) );
            adj[q].pb( pii(p,state) );
        }

    int sz=adj[1].size();
    int cnt=0;
    vector<int> output;
    vis[1]=1;

    for(int i=0;i<sz;i++)
    {
        if(!vis[adj[1][i].first])
        {
            vis[adj[1][i].first]=1;
            if(adj[1][i].second==2)
                ans=adj[1][i].first;
            traverse(adj[1][i].first);
            if(ans!=0)
                output.pb(ans);
        }
    }

    sz=output.size();
    cout<<sz<<endl;
    for(int i=0;i<sz;i++)
        cout<<output[i]<<" ";

}
