#include <bits/stdc++.h>
using namespace std;

char grid[26][26];
bool vis[26][26];
int dim;

int moves1[]= {-1,0,1,0,1,-1,-1,1};
int moves2[]= {0,1,0,-1,-1,1,-1,1};

bool isvalid( int i, int j )
{
    if( i<0 or j<0 )
        return 0;
    if(i>=dim or j>=dim)
        return 0;
    if( vis[i][j] )
        return 0;
    if( grid[i][j]=='0' )
        return 0;
    return 1;
}

void dfs( int r, int c )
{
    vis[r][c]= 1;

    for(int i=0; i<8; i++)
        if( isvalid(r+moves1[i],c+moves2[i]) )
            dfs( r+moves1[i], c+moves2[i] );
}

int main()
{
    int tc= 1;

    while(cin>>dim)
    {
        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                cin>>grid[i][j];

        int cnt= 0;

        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                if( isvalid(i,j) )
                {
                    dfs(i,j);
                    cnt++;
                }

        cout<<"Image number "<<tc++<<" contains "<<cnt<<" war eagles.\n";
        memset( vis, 0, sizeof(vis) );
    }
}
