#include <bits/stdc++.h>
#define ll long long
#define m 1000000007;
using namespace std;

char grid[1007][1007];
ll dp[1007][1007];
bool vis[1007][1007];
int h,w;

bool valid( int i, int j )
{
    if( i<0 or j<0 )
        return 0;
    if( i>=h or j>=w )
        return 0;
    if( grid[i][j]=='#' )
        return 0;
    return 1;
}

ll rec( int i, int j )
{
    if( i==h-1 and j==w-1 )
        return 1;
    if(vis[i][j])
        return dp[i][j];

    ll q1= 0, q2= 0;

    if( valid(i+1,j) )
        q1= rec( i+1,j )%m;
    if( valid(i,j+1) )
        q2= rec( i, j+1 )%m;

    vis[i][j]= 1;

    return dp[i][j]= (q1+q2)%m;
}

int main()
{
    cin>>h>>w;

    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>grid[i][j];

    cout<< rec(0,0) <<endl;

}

