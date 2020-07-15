#include <bits/stdc++.h>
#define mx 107
using namespace std;

int aa[mx], bb[mx];
vector<int> adj[mx];
bool vis[mx];
int mr[mx], ml[mx];

int dfs( int y )
{
    vis[y]= 1;
    for( int i=0; i<adj[y].size(); i++ )
    {
        int z= adj[y][i];

        if( mr[z]==-1 or (!vis[ mr[z] ]  and dfs( mr[z] ) ) )
        {
            ml[y]= z;
            mr[z]= y;
            return 1;
        }
    }

    return 0;
}

int main()
{
    int tc;
    cin>>tc;

    for( int t=1; t<=tc; t++ )
    {
        memset( mr, -1, sizeof(mr) );
        memset( ml, -1, sizeof(ml) );

        int n;
        scanf("%d", &n);

        for( int i=0;i<n;i++ )
            scanf("%d", &aa[i]);

        int m;
        scanf("%d", &m);

        for( int i=0;i<m;i++ )
            scanf("%d", &bb[i]);

        for( int i=0; i<n; i++ )
            for( int j=0; j<m; j++ )
                if( bb[j]%aa[i]==0 )
                    adj[ i ].push_back( j );


        int ans= 0;
        for( int i=0; i<n; i++ )
        {
            memset( vis,0,sizeof(vis) );

            ans+= dfs( i );
        }

        cout<<"Case "<<t<<": "<<ans<<endl;

        for( int i=0;i<n;i++ )
            adj[i].clear();
    }
}

