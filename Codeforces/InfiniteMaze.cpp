#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int n,m;
int d1[]={1,0,-1,0};
int d2[]={0,1,0,-1};
bool vis[1600][1600];
bool vis2[1600][1600];
char grid[1600][1600];
bool pos;

void dfs2( int x, int y, int cnt, int p, bool step );
int op( int p )
{
    if(p==0)
        return 2;
    if(p==2)
        return 0;
    if(p==1)
        return 3;
    if(p==3)
        return 1;
    return 100;
}

int isValid( int x, int y)
{
    if( x<0 or x>=n )
        return 0;
    if( y<0 or y>=m )
        return 0;
    if( grid[x][y]=='#' )
        return -1;
    return 1;
}

pii nextIfNotValid( int x, int y, int i )
{
    if( i==0 )
        return pii( 0, y );
    if( i==1 )
        return pii( x, 0 );
    if( i==2 )
        return pii( n-1, y );
    return pii( x, m-1 );
}

void dfs( int x, int y, int cnt, int p, bool step )
{
    if(pos)
        return;
    if( cnt>1 )
    {
        pos= 1;
        return;
    }

    vis[x][y]= 1;
    int now= op(p);

    for(int i=0;i<4;i++)
    {
        if( step and now==i )
            continue;
        int ux= x+d1[i];
        int uy= y+d2[i];

        if( vis[ux][uy] )
            continue;

        if( isValid(ux,uy)==1 )
            dfs( ux,uy,cnt,p,0 );
        else if(isValid(ux,uy)==0)
        {

            int vx= nextIfNotValid(ux,uy,i).first;
            int vy= nextIfNotValid(ux,uy,i).second;
//cout<<"Dhukse\n "<<ux<<" "<<uy<<endl;
            if( grid[vx][vy]=='.' or grid[vx][vy]=='S' )
                dfs2( vx,vy, cnt+1,i,1 );
        }

    }
}

void dfs2( int x, int y, int cnt, int p, bool step )
{
    if(pos)
        return;
    cout<<x<<" "<<y<<" "<<cnt<<endl;
    if( cnt>1 )
    {
        pos= 1;
        return;
    }

    vis2[x][y]= 1;
    int now= op(p);

    for(int i=0;i<4;i++)
    {
        if( step and now==i )
            continue;
        int ux= x+d1[i];
        int uy= y+d2[i];

        if( vis2[ux][uy] )
            continue;

        if( isValid(ux,uy)==1 )
            dfs2( ux,uy,cnt,p,0 );
        else if(isValid(ux,uy)==0)
        {
            int vx= nextIfNotValid(ux,uy,i).first;
            int vy= nextIfNotValid(ux,uy,i).second;
//cout<<"Dhukse\n "<<ux<<" "<<uy<<endl;
            if( grid[vx][vy]=='.' or grid[vx][vy]=='S' )
                dfs2( vx,vy, cnt+1,i,1 );
        }

    }
}

int main()
{
    cin>>n>>m;
    int x,y;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                cin>> grid[i][j];

                if(grid[i][j]=='S')
                    x= i, y= j;
            }

    dfs( x,y,0,100,1 );

    if(pos)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

/*
4 4
####
.#S.
.###
.###
*/
