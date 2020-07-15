#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define INF 1e4+5
using namespace std;
bool flag=0;
queue <int> q;
unsigned int vec[10005][3];
int n,m,u,ans;
int level[10001];
void bfs()
{
    while(!flag)
    {



        int first=q.front();

        q.pop();
        vec[first][0]=first*2;
        vec[first][1]=first-1;

        for(int i=0; i<2; i++)
        {if(vec[first][i]>0){
            cout<<vec[first][i]<<endl;
          if(level[vec[first][i]]>(level[first]+1))
            level[vec[first][i]]=level[first]+1;
          if(vec[first][i]==m)
          {
              ans=level[vec[first][i]];
              flag=1;
              break;
          }}
          if(vec[first][i]>0)q.push(vec[first][i]);
        }
    }
};

int main()
{

    memset(level, INF, sizeof(level));
    cin>>n>>m;
    level[n]=0;
    if(n>m)
    {
        ans=n-m;
    }
    else
    {
        q.push(n);

        bfs();
    }
    cout<<ans;
    return 0;
}
