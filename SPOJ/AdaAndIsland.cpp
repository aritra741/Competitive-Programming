#include <bits/stdc++.h>
#define ll long long
using namespace std;

char grid[1010][1010];
bool vis[1010][1010];
int d1[]= {1,0,-1,0};
int d2[]= {0,-1,0,1};
ll n,m;

bool valid( int x, int y )
{
    if( x<0 or x>=n )
        return 0;
    if( y<0 or y>=m )
        return 0;
    if( grid[x][y]=='~' or vis[x][y] )
        return 0;
    return 1;
}

int dfs( int x, int y )
{
    vis[x][y]= 1;
    int cnt= 1;

    for( int i=0; i<4; i++ )
    {
        int x1= x+d1[i];
        int y1= y+d2[i];

        if( !valid(x1,y1) )
            continue;

        cnt+= dfs( x1,y1 );
    }
   // cout<<x<<" "<<y<<" "<<cnt<<endl;
    return cnt;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n>>m;

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>> grid[i][j];

        memset( vis,0,sizeof(vis) );

        ll numer= 0, denom= n*m;

        for( int i=0; i<n; i++ )
            for(int j=0; j<m; j++)
            {
                ll now= 0;
                if( !vis[i][j] and grid[i][j]=='#' )
                    now=dfs(i,j), numer+=now*now ;
            }

        if( !numer )
        {
            cout<< "0\n";
            continue;
        }

        if( numer==denom )
        {
            cout<< "1\n";
            continue;
        }

        ll Numer=numer/__gcd(numer,denom);
        ll Denom=denom/__gcd(numer,denom);

        if( Denom==1 )
        {
            cout<< Numer <<endl;
            continue;
        }

        cout<< Numer <<" / "<< Denom <<endl;
    }
}
