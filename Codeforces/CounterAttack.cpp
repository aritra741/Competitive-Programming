#include <bits/stdc++.h>
using namespace std;

set<int>  unv;
set<int> ::iterator it;
vector<int> adj[500007], ans[500007];
int cc;

void bfs( int x )
{
    unv.erase( x );

    queue<int>q;
    q.push(x);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        ans[cc].push_back(u);
        vector<int> temp;

        for(it= unv.begin(); it!=unv.end(); it++)
        {
            int v= (*it);
            if( !binary_search(adj[u].begin(),adj[u].end(),v) )
            {
                q.push(v);
                temp.push_back(v);
            }
        }

        for(int i=0;i<temp.size();i++)
            unv.erase(temp[i]);
    }

}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    while(m--)
    {
        int p,q;
        scanf("%d %d", &p,&q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    for(int i=1;i<=n;i++)
        unv.insert(i),
        sort( adj[i].begin(),adj[i].end() );

    for(int i=1;i<=n;i++ )
    {
        if( unv.find(i)==unv.end() )
            continue;

        bfs(i);
        cc++;
    }

    printf("%d\n", cc);

    for(int i=0;i<cc;i++)
    {
        printf("%d ", ans[i].size());

        for(int j=0;j<ans[i].size();j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}
