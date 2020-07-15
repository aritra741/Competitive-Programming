#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int ROW=0,COL=1,num=0;
int vis[100][100];
char grid[100][100];
void dfs(int row, int col)
{
    int l1[]={-1,0,1,0};
    int l2[]={0,1,0,-1};
    for(int i=0;i<4;i++)
        if( (row+l1[i]>0 && col+l2[i]>0 && row+l1[i]<=ROW && col+l[i]<=COL && grid[row+l1[i]][col+l[i]]=='W' vis[row+l1[i]][col+l[i]]==0)
            {
                vis[row+l1[i]][col+l[i]]=1;
                num++
                dfs(row+l1[i],col+l2[i]);
            }
}
int main()
{
    memset(vis, 0, sizeof(vis));
    int tc;cin>>tc;
    while(tc--)
    {
        num=0;
        for(int x=1;;x++)
            {
                COL=0;

            for(int y=1;;y++)
                while((grid[x][y]=getchar())!='\n')
                {
                    COL++;
                }
                ROW++;
            }
    }
    return 0;
}
