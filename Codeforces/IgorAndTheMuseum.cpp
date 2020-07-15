#include <bits/stdc++.h>
using namespace std;

int n,m;
int d1[]= {1,0,-1,0};
int d2[]= {0,1,0,-1};
int  vis[1100][1100];
char grid[1100][1100];
int ans[1000007];
int cnt, p;

int isValid( int x, int y )
{
    if( x<0 or x>=n )
        return 0;
    if( y<0 or y>=m )
        return 0;
    if( grid[x][y]=='*' )
        return -1;
    return 1;
}

void dfs( int x, int y )
{
    vis[x][y]= p;

    for(int i=0; i<4; i++)
    {
        int ux= x+d1[i];
        int uy= y+d2[i];

        if( vis[ux][uy] )
            continue;

        if( isValid(ux,uy)==1 )
            dfs( ux,uy );
        else if( isValid(ux,uy)==-1 )
            cnt++;
    }
}

int main()
{
    int k;
    cin>>n>>m>>k;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>> grid[i][j];

    while(k--)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;

        if( !vis[x][y] )
        {
            p++;
            cnt= 0;
            dfs(x,y);

            ans[p]= cnt;
        }

        cout<< ans[ vis[x][y] ] <<endl;

    }
}
