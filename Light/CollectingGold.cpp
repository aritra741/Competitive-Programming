#include <bits/stdc++.h>
#define inf 1e9;
using namespace std;

char grid[25][25];
int pos[25][2], dist[25][25];
int dp[25][65540];
int vis[25][65540];
int n,m,p,done,cnt;

int rec( int i, int mask )
{
    if(mask==done)
        return dist[i][0];
    if( vis[i][mask]==p )
        return dp[i][mask];

    int ans= inf;
    for(int j=1;j<cnt;j++)
    {
        if( mask&(1<<j) )
            continue;
        ans=min( ans, dist[i][j]+rec( j, mask|(1<<j) ) );
    }

    vis[i][mask]= p;

    return dp[i][mask]= ans;
}

void init()
{
    cnt= 1;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            if( grid[i][j]=='x' )
                pos[0][0]= i, pos[0][1]= j;
            else if( grid[i][j]=='g' )
                pos[cnt][0]= i, pos[cnt][1]= j, cnt++;
        }

    for(int i=0; i<cnt; i++)
        for(int j=0; j<cnt; j++)
            dist[i][j]= max( abs( pos[i][0]-pos[j][0] ), abs(pos[i][1]-pos[j][1]) );
}

int main()
{
   int tc;
   cin>>tc;

   for(int t=1;t<=tc;t++)
   {
        p++;
    cin>>m>>n;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];

    init();
    done= (1<<cnt)-1;

    cout<<"Case "<<t<<": "<< rec( 0, 1 ) <<endl;

   }
}
