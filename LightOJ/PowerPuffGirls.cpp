#include <bits/stdc++.h>
#define pii pair<int, int>
#define MAX(a,b,c) max(a, max(b,c) );
using namespace std;

char g[21][21];
bool vis[21][21];
int lvl[21][21];

int cnt[3];

queue <pair <int, int> > q;

int dir1[]= {1,0,-1,0};
int dir2[]= {0,-1,0,1};

int bfs(int row, int col)
{
    while(!q.empty())
    {
    int u=q.front().first;
    int v=q.front().second;
    if(g[u][v]=='h')
        return lvl[u][v];
    q.pop();
    for(int i=0; i<4; i++)
    {

//        cout<<u<<" "<<v<<endl;
        if(u+dir1[i]<row && v+dir2[i]<col && u+dir1[i]>0 && v+dir2[i]>0 && g[u+dir1[i]][v+dir2[i]]!='#' && g[u+dir1[i]][v+dir2[i]]!='m' )
            if(!vis[u+dir1[i]][v+dir2[i]])
            {
                lvl[u+dir1[i]][v+dir2[i]]=lvl[u][v]+1;
                vis[u+dir1[i]][v+dir2[i]]=1;
                q.push( pii(u+dir1[i], v+dir2[i]) );
            }
    }
    }
}

int main()
{
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        int row, col;
        scanf("%d %d", &row, &col);
        int ax,bx,cx,hx,ay,by,cy,hy;
        for(int j=0; j<row; j++){
            for(int k=0; k<col; k++)
            {

                cin>>g[j][k];
                if(g[j][k]=='a')
                {
                    ax=j;
                    ay=k;
                }

                else if(g[j][k]=='b')
                {
                    bx=j;
                    by=k;
                }

                else if(g[j][k]=='c')
                {
                    cx=j;
                    cy=k;
                }

                else if(g[j][k]=='h')
                {
                    hx=j;
                    hy=k;
                }

            }
        }
        lvl[ax][ay]=0;
        vis[ax][ay]=1;
        q.push(pii(ax, ay));
        cnt[0]=bfs(row, col);
        q= queue<pii> ();
        memset(vis, 0 , sizeof(vis));
//        cout<<lvl[hx][hy]<<endl;
        for(int p=0;p<5;p++)
            for(int o=0;o<21;o++)
                lvl[p][o]=0;
        lvl[bx][by]=0;
        q.push(pii(bx, by));
        vis[bx][by]=1;
        cnt[1]=bfs(row, col);
        memset(vis, 0 , sizeof(vis));
        q= queue<pii> ();
        for(int p=0;p<5;p++)
            for(int o=0;o<21;o++)
                lvl[p][o]=0;
        lvl[cx][cy]=0;
        vis[cx][cy]=1;
        q.push(pii(cx, cy));
        cnt[2]=bfs(row, col);
        memset(vis, 0 , sizeof(vis));
        q= queue<pii> ();
        for(int p=0;p<5;p++)
            for(int o=0;o<21;o++)
                lvl[p][o]=0;
//        cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;
        int ans= MAX(cnt[0], cnt[1],cnt[2]);
        printf("Case %d: %d\n", i, ans);
    }
}
