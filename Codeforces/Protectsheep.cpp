#include <bits/stdc++.h>
using namespace std;
bool flag=0;
void dfs(int y, int x)
{
    int l[]={0,-1,0,1};
    int m[]={1,0,-1,0};
    for(int i=0;i<4;i++)
    {

        if((x+m[i])>=0 && (x+m[i])<l && (y+l[i])>=0 && (y+l[i])<k && vis[y+l[i]][x+m[i]]==0)
        {
            if(ch[y+l[i]][x+m[i]]=='W')

            vis[y+l[i]][x+m[i]]=1;

        n++;

          dfs(y+l[i],x+m[i]);
        }
    }
};

int main()
{
    int k,l;
    cin>>k>>l;
    vis[k][l];
    for(int p=0;p<k;p++)
        for(int q=0;q<l;q++)
            vis[p][q]=0;
    char grid[k][l];
    int r[k*l],c[k*l],i=0;
    for(int p=0;p<k;p++)
        for(int q=0;q<l;q++)
            {
                cin>>grid[p][q];
                    if(grid[p][q]=='W')
                      {
                    r[i]=p;c[i]=q;
                            i++;
                      }
            }

}
