#include <bits/stdc++.h>
#define pii pair<int,int>
#define inf 0x3f3f3f
using namespace std;

char grid[1010][1010];
int dist[1010][1010];
int d1[]= {1,0,0,-1};
int d2[]= {0,-1,1,0};
int n,m,k,x,y;

bool valid( int x, int y )
{
    if( x<0 or y<0 )
        return 0;
    if( x>=n or y>=m )
        return 0;
    if( grid[x][y]=='*' )
        return 0;
    return 1;
}

int main()
{
    cin>>n>>m>>k;

    if(k&1)
        return cout<< "IMPOSSIBLE" <<endl, 0;

    memset( dist, inf, sizeof(dist) );

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                cin>> grid[i][j];

                if( grid[i][j]=='X' )
                    x= i, y= j;
            }

    queue<pii> q;
    q.push( pii(x,y) );
    dist[x][y]= 0;

    while(!q.empty())
    {
        int X= q.front().first;
        int Y= q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            int x1= X+d1[i];
            int y1= Y+d2[i];

            if( !valid( x1,y1 ) )
                continue;

            if( dist[X][Y]+1<dist[x1][y1] )
            {
                dist[x1][y1]= dist[X][Y]+1;
                q.push( pii(x1,y1) );
            }
        }
    }

    string ans;

    while(k--)
    {
        if( valid(x+1,y) and dist[x+1][y]<=k )
            ans+= "D", x++;
        else if( valid(x,y-1) and dist[x][y-1]<=k )
            ans+= "L", y--;
        else if( valid(x,y+1) and dist[x][y+1]<=k )
            ans+= "R", y++;
        else if( valid(x-1,y) and dist[x-1][y]<=k )
            ans+= "U", x--;
        else
            return cout<< "IMPOSSIBLE" <<endl, 0;
    }

    cout<< ans <<endl;

}
