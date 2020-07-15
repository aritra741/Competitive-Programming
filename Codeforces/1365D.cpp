#include<bits/stdc++.h>
using namespace std;

bool vis[55][55];
string s[55];
int n,m;

int d1[]= {1,0,-1,0};
int d2[]= {0,-1,0,1};

bool valid( int x, int y )
{
    if( x<0 or y<0 )
        return 0;
    if( x>=n or y>=m )
        return 0;
    if( s[x][y]=='#' )
        return 0;
    return 1;
}

void dfs( int x, int y )
{
    if( vis[x][y] or !valid(x,y) )
        return;

    vis[x][y]= 1;

    for( int i=0; i<4; i++ )
        if( valid( x+d1[i], y+d2[i] ) )
            dfs( x+d1[i], y+d2[i] );
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        memset( vis, 0, sizeof(vis) );

        cin>>n>>m;

        for( int i=0; i<n; i++ )
            cin>>s[i];

        bool ok= 0;

        dfs( n-1, m-1 );

        bool f= 0;

        for( int i=0; i<n; i++ )
            for( int j=0; j<m; j++ )
            {
                if( s[i][j]!='B' or !vis[i][j] )
                    continue;

                for( int k=0;k<4;k++ )
                    if( valid( i+d1[k], j+d2[k] ) )
                    {
                        if( vis[ i+d1[k] ][ j+d2[k] ] )
                        {
                            if( s[ i+d1[k] ][ j+d2[k] ]=='G' )
                            {
                                f= 1;
                                break;
                            }
                            if( s[ i+d1[k] ][ j+d2[k] ]!='B' )
                                s[ i+d1[k] ][ j+d2[k] ]= '#';
                        }
                    }

            }

        if(f)
        {
            cout<<"No\n";
            continue;
        }

        memset( vis, 0, sizeof(vis) );

        dfs( n-1,m-1 );

        for( int i=0; i<n; i++ )
            for( int j=0; j<m; j++ )
            {
                if( s[i][j]=='B' and vis[i][j] )
                    f= 1;
                if( s[i][j]=='G' and !vis[i][j] )
                    f= 1;
            }

        if(f)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}
