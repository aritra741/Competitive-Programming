#include <bits/stdc++.h>
#define MX 300007
using namespace std;

vector <int> adj[MX], seq, bfs;
map <int, int> pos;
int lvl[MX];
bool vis[MX];
int indegree[MX];

bool cmp( const int &a, const int &b )
{
    return pos[a]<pos[b];
}

int main()
{
    int n;
    scanf( "%d", &n );

    for(int i=1; i<n; i++)
    {
        int p,q;
        scanf("%d %d", &p,&q);
        adj[p].push_back(q);
        adj[q].push_back(p);
        indegree[q]++;
    }

    for(int i=0; i<n; i++)
    {
        int p;
        scanf("%d", &p);
        seq.push_back(p);
        pos[p]=i;
    }

    for(int i=1; i<=n; i++)
        sort( adj[i].begin(), adj[i].end(), cmp );

    queue <int> q;
    q.push(1);
    vis[1]=1;

    while(!q.empty())
    {
        int u= q.front();
        bfs.push_back(u);
        q.pop();

        int sz= adj[u].size();

        for(int i=0; i<sz; i++)
        {
            int v= adj[u][i];
            if(!vis[v])
            {
                vis[v]=1;
                lvl[v]= lvl[u]+1;
                q.push(v);
            }
        }
    }
    bool flag=0;

    if(seq[0]!=1)
        flag=1;

    else
    {

        for(int i=0; i<n; i++)
            if(seq[i]!=bfs[i])
                flag=1;
    }
    if(flag)
        printf("No\n");
    else
        printf("Yes\n");



}
