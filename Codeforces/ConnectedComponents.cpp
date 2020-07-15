#include <bits/stdc++.h>
using namespace std;

set<int> unv;
set<int> ::iterator it;
vector<int> adj[200007], v;
int cc;

void bfs( int x )
{
    queue<int> q;
    q.push( x );
    unv.erase( unv.find(x) );
    while(!q.empty())
    {
        cc++;
        int u= q.front();
        q.pop();

        int sz= adj[u].size();
        vector<int> temp;

        for( it= unv.begin(); it!=unv.end(); it++ )
        {
            int v= (*it);

            if( !binary_search(adj[u].begin(),adj[u].end(), v) )
            {
                temp.push_back(v);
                q.push(v);
            }
        }

        for(int i=0; i<temp.size(); i++)
            unv.erase(unv.find(temp[i]));
    }
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++)
    {
        int p,q;
        scanf("%d %d", &p, &q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    for(int i=1; i<=n; i++)
        unv.insert(i),
        sort(adj[i].begin(),adj[i].end());

    for(int i=1; i<=n; i++)
    {
        if( unv.find(i)==unv.end() )
            continue;

        cc= 0;

        bfs(i);
        v.push_back(cc);
    }

    sort( v.begin(),v.end() );

    printf("%d\n", v.size());

    for(int i=0; i<v.size(); i++)
        printf("%d ", v[i]);
}
