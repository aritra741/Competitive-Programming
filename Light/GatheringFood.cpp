#include <bits/stdc++.h>
#define pii pair<int,int>
#define mset(x,i) memset(x,i, sizeof(x))
#define d(x) cout<<x<<endl
using namespace std;

int row,col;
bool vis[200][200];
char grid[200][200];
int lvl[200][200];
char tar;
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

bool isValid( int x, int y )
{
    if( x>=row or y>=col or x<0 or y<0 or grid[x][y]=='#' or grid[x][y]>tar )
       return 0;
    return 1;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n;
        cin>>n;
        row=n,col=n;

        int cnt=0;
        int x,y;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                {
                    cin>>grid[i][j];
                    if(grid[i][j]<='Z' and grid[i][j]>='A')
                        cnt++;
                    if(grid[i][j]=='A')
                        x=i,y=j;
                }

        cout<<"Case "<<t<<": ";
        char curr='A';
        tar='B';
        int tot=0;
        bool found=0;
        bool fir=1;
        int done=1;

        while(tar-'A'+1<=cnt)
        {
            if(found)
                found=0;
            else if(found==0 and fir==0)
                break;
            fir=0;
            mset(vis, 0);
            queue <pii> q;
            q.push( pii(x,y) );
            vis[x][y]=1;
            lvl[x][y]=0;

            while(!q.empty())
            {
            //    d("q er moddhe");
                int u=q.front().first;
                int v=q.front().second;
                q.pop();

                if(found)
                    break;

                for(int k=0;k<4;k++)
                {
                    if( isValid( u+dx[k], v+dy[k] ) and !vis[u+dx[k]][v+dy[k]] )
                    {
                        vis[u+dx[k]][v+dy[k]]=1;
                        lvl[u+dx[k]][v+dy[k]]=lvl[u][v]+1;
                        if( grid[u+dx[k]][v+dy[k]]==tar )
                            {
                                found=1;
                                x=u+dx[k],y=v+dy[k];
                            }
                        else
                            q.push( pii(u+dx[k], v+dy[k]) );
                    }
                }

            }

            if(found)
            {
                tar++;
                tot+=lvl[x][y];
                mset(lvl,0);
                done++;
            }
        }

        if(cnt!=done)
            cout<<"Impossible"<<endl;
        else
            cout<<tot<<endl;

    }
}


