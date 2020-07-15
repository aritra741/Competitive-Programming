#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

set<int> adj[250];
int mat[250][250];
int deg[250];
vector<int> odd, ans;


void euler_path( int u )
{
    while( !adj[u].empty() )
    {
        int v= *adj[u].begin();
        adj[u].erase(v);
        adj[v].erase(u);

        if( mat[u][v]==1 )
            ans.push_back( u ),
            ans.push_back( v );

        euler_path( v );
    }

    ans.push_back(u);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,m;
        cin>>n>>m;

        for( int i=0; i<m; i++ )
        {
            int p,q;
            cin>>p>>q;

            adj[p].insert( q );
            adj[q].insert( p );
            mat[p][q]= 1;
            mat[q][p]= 1;

            deg[p]++, deg[q]++;
        }

        for( int i=1; i<=n; i++ )
            if( deg[i]&1 )
                odd.push_back(i);

        for( int i=1; i<odd.size(); i+=2 )
            adj[ odd[i] ].insert( odd[i-1] ),    /// Even number of vertices with odd degree
            adj[ odd[i-1] ].insert( odd[i] ),
            mat[odd[i]][odd[i-1]]= 2,
            mat[odd[i-1]][odd[i]]= 2;

        euler_path( odd[0] );

        cout<< ans.size() <<endl;

        for( int i=1; i<ans.size(); i++ )
            cout<< ans[i-1] <<" "<< ans[i] <<endl;
    }
}
