#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<pii> v;
char grid[55][55];
bool vis[55][55];
int d1[]= {1,0,-1,0};
int d2[]= {0,-1,0,1};
int n,m;

bool valid( int x, int y )
{
    if(x<0 or y<0)
        return 0;
    if(x>=n or y>=m)
        return 0;
    if(grid[x][y]=='W' or vis[x][y])
        return 0;
    return 1;
}

void dfs( int x, int y )
{
    vis[x][y]= 1;

    for(int i=0;i<4;i++)
    {
        int x1= x+d1[i];
        int y1= y+d2[i];

        if( !valid(x1,y1) )
            continue;

        dfs( x1,y1 );
    }
}

int main()
{
    while(scanf("%d %d", &n, &m)==2)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                {
                    cin>> grid[i][j];

                    if( grid[i][j]=='L' )
                        v.push_back( pii(i,j) );
                }

        int cnt= 0;
        for(int i=0;i<v.size();i++)
        {
            if( vis[v[i].first][v[i].second] )
                continue;
            dfs( v[i].first,v[i].second );
            cnt++;
        }

        cout<< cnt <<endl;

        memset( vis, 0, sizeof(vis) );
        v.clear();
    }
}
