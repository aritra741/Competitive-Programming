#include <bits/stdc++.h>
using namespace std;

char g[51][51];
int state[51][51];

int rook1[]={1,0,-1,0};
int rook2[]={0,1,0,-1};

bool flag=0;

void dfs( int row, int col, int r, int c, int src_row, int src_col )
{
    char u=g[r][c];
    state[r][c]=1;
    for(int i=0;i<4;i++)
    {
        if(r+rook1[i]<row and c+rook2[i]<col and  r+rook1[i]>=0 and c+rook2[i]>=0 and  g[r+rook1[i]][c+rook2[i]]==u)
        {
            if(r+rook1[i]==src_row and c+rook2[i]==src_col)
                continue;
            if(state[r+rook1[i]][c+rook2[i]]==1)
            {
                flag=1;
                return;
            }
            dfs( row, col, r+rook1[i], c+rook2[i], r, c  );

        }
    }
    state[r][c]=2;

}

int main()
{
    int row,col;
    cin>>row>>col;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>g[i][j];
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            if( state[i][j]==0 )
                dfs(row, col, i, j, -2, -2);
        }

    if(flag)
        cout<<"Yes";
    else
        cout<<"No";

}
