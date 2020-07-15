#include <bits/stdc++.h>
#define mx 200007
using namespace std;

vector<int> adj[mx], ans;
bool vis[mx];

void euler( int u )
{
    vis[u]= 1;
    ans.push_back(u);
    bool f= 0;

    for(int i=0;i<adj[u].size();i++)
    {
        int v= adj[u][i];

        if(vis[v])
            continue;

        euler(v);
        ans.push_back(u);
    }

}

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=0;i<m;i++)
    {
        int p,q;
        scanf("%d %d", &p, &q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    euler(1);

    int tot= (2*n+k-1)/k;

    for( int i=0;i<k;i++ )
    {
        int st= i*tot;
        if(st>ans.size()-1)
            st= ans.size()-1;

        int now= min( (int)ans.size(),i*tot+tot )-st;
        printf("%d ", now);

        for( int j=st;j<min((int)ans.size(),i*tot+tot);j++ )
            printf("%d ", ans[j]);
        printf("\n");
    }
}
