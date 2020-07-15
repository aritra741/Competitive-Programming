#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> adj[1000007], ans;
bool vis[1000007];
int t[1000007], sum[1000007], tot, root;

int dfs( int u )
{
    vis[u]= 1;
    int cnt= t[u];

    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];

        if( vis[v] )
            continue;
        cnt+= dfs(v);
    }

    if( cnt==tot/3 and u!=root and ans.size()<2 )
        ans.push_back(u),
        cnt= 0;

    return sum[u]= cnt;
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int p,q;
        scanf("%d %d", &p, &q);

        if( p )
            adj[p].push_back(i);
        else
            root= i;
        t[i]= q;
        tot+= q;
    }

    if( tot%3 )
        return cout<<"-1"<<endl, 0;

    dfs(root);

    if( ans.size()!=2 )
        return cout<<"-1"<<endl, 0;

    cout<< ans[0] <<" "<< ans[1] <<endl;
}
