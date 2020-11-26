#include <bits/stdc++.h>
#define mx 1007
using namespace std;

vector<int> aa,bb;
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
    memset( mr, -1, sizeof(mr) );
    memset( ml, -1, sizeof(ml) );
    int a,b;
    scanf("%d %d", &a, &b);

    int n;
    scanf("%d", &n);

    for( int i=0; i<n; i++ )
    {
        int p,q;
        scanf("%d %d", &p, &q);

        if( q==1 )
            bb.push_back( p );
        else
            aa.push_back( p );
    }

    if( aa.size()!=bb.size() )
        return cout<<"Liar\n", 0;

    int m= aa.size();

    for( int i=0; i<m; i++ )
        for( int j=0; j<m; j++ )
            if( bb[j]>aa[i] and (aa[i]+b>=bb[j] or aa[i]+a<=bb[j]) )
                adj[ i ].push_back( j );


    int ans= 0;
    for( int i=0; i<m; i++ )
    {
        memset( vis,0,sizeof(vis) );

        ans+= dfs( i );
    }

    if( ans!=m )
        return cout<<"Liar\n", 0;

    cout<<"No reason\n";

    for( int i=0; i<m; i++ )
        cout<<aa[i]<<" "<<bb[ ml[i] ]<<endl;
}

