#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
using namespace std;

int rook1[]= {1,0,-1,0};
int rook2[]= {0,-1,0,1};

bool vis[500][500];
char arr[500][500];

int cnt=0;

void dfs(int x, int y, int row, int col)
{
    //cout<<arr[x][y]<<endl;
    if(arr[x][y]=='C'){
        cnt++;//cout<<"YES"<<endl;
    }

    for(int i=0; i<4; i++)
    {
        int u=x+rook1[i];
        int v=y+rook2[i];
        if(u>=0 && u<row && v>=0 && v<col && arr[u][v]!='#')
        {
            if(vis[u][v]==0)
            {
                vis[u][v]=1;
                dfs(u, v, row, col);
            }
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int t=1; t<=tc; t++)
    {
        int row, col, q;
        scanf("%d %d %d", &row, &col, &q);
        getchar();
        for(int i=0; i<row; i++)
            scanf("%s", arr[i]);
        printf("Case %d:\n", t);
        int ans[row][col];
        memset(ans, -1, sizeof(ans));


        for(int i=0; i<q; i++)
        {
            int x,y;
            scanf("%d %d", &x, &y);
            if(ans[x-1][y-1]!=-1)
                printf("%d\n", ans[x-1][y-1]);
            else
            {
                dfs(x-1, y-1, row, col);
                ans[x-1][y-1]=cnt;
                for(int j=0; j<row; j++)
                    for(int k=0; k<col; k++)
                        if(vis[j][k]==1)
                            ans[j][k]=cnt;
                    cnt=0;
                for(int j=0; j<row; j++)
                    for(int k=0; k<col; k++)
                        vis[j][k]=0;
                printf("%d\n", ans[x-1][y-1]);
            }

        }




    }
}
