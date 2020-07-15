#include <bits/stdc++.h>
#define mx
using namespace std;

vector<int> adj[mx];

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    for( int i=0;i<m;i++ )
    {
        int p,q;
        scanf("%d %d", &p,&q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    for( int i=1;i<=n;i++ )
    {
        adj[i].push_back(i);
        sort( adj[i].begin(), adj[i].end() );
    }


}
