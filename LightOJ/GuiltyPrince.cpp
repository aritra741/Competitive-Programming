#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int w,h,x,y;
char ch[25][25];
int vis[25][25];
int n=0;

void dfs(int y, int x)
{
    int l[]={0,-1,0,1};
    int m[]={1,0,-1,0};
    for(int i=0;i<4;i++)
    {

        if((x+m[i])>=0 && (x+m[i])<w && (y+l[i])>=0 && (y+l[i])<h && vis[y+l[i]][x+m[i]]==0 && ch[y+l[i]][x+m[i]]=='.')
        {
            vis[y+l[i]][x+m[i]]=1;

        n++;

          dfs(y+l[i],x+m[i]);
        }
    }
};
int main()
{

        int tc;cin>>tc;
        for(int k=1;k<=tc;k++){
                n=0;
        scanf("%d %d", &w, &h);    //w and x=number of cols, h and y=number of rows
        for(int p=0;p<=24;p++)
            for(int q=0;q<=24;q++)
                vis[p][q]=0;


       for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++)
{


                cin>>ch[i][j];
				if(ch[i][j] == '@') {
					y = i;
					x = j;
					n = 1;
                    vis[y][x]=1;
				}



		}
}

        dfs(y,x);

cout<<"Case "<<k<<": "<<n<<endl;


        }
     return 0;
}

/* 2
4 2
@.
.#
.#
#. */
