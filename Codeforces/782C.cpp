#include<bits/stdc++.h>
#define mx 200007
using namespace std;

vector<int>adj[mx];
int par[mx], col[mx];
int ans[mx];

void bfs()
{
    queue<int>q;
    q.push(1);
    col[1]= 1;

    while( !q.empty() )
    {
        int u= q.front();
        q.pop();

        int kk= 1;

        for( auto v: adj[u] )
            if( v!=par[u] )
            {
                for( int i=kk; i<mx; i++ )
                    if( i!=col[u] and i!=col[ par[u] ] )
                    {
                        kk= i;
                        break;
                    }
                par[v]= u;
                q.push(v);
                col[v]= kk++;
            }
        }
}

int main()
{
    int n;
    cin>>n;

    for( int i=1; i<n; i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    int ans= 1;

    for( int i=1; i<=n; i++ )
        ans= max( ans, (int)adj[i].size()+1 );

    bfs();

    cout<<ans<<endl;
    for( int i=1; i<=n; i++ )
        cout<<col[i]<<" ";
}
