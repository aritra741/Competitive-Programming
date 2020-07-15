#include <bits/stdc++.h>
using namespace std;

char ch[101][101];
bool vis[101][101];

void dfs(int y, int x, int w, int h)
{
    int l[]={0,-1,0,1,1,-1,1,-1};
    int m[]={1,0,-1,0,1,-1,-1,1};
    for(int i=0;i<8;i++)
    {

        if((x+m[i])>=0 && (x+m[i])<w && (y+l[i])>=0 && (y+l[i])<h && vis[y+l[i]][x+m[i]]==0 && ch[y+l[i]][x+m[i]]=='@')
        {
            vis[y+l[i]][x+m[i]]=1;

          dfs(y+l[i],x+m[i], w, h);
        }
    }
}

int main()
{
    while(1){
    int row, col;
    cin>>row>>col;
    if(row==0 && col==0)
        return 0;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>ch[i][j];
    int cnt=0;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            if(ch[i][j]=='@' && !vis[i][j])
            {
                cnt++;
                dfs(i, j, col, row);
            }
        }
    cout<<cnt<<endl;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            vis[i][j]=0;


    }
}
