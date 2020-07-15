#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

bool mat[25][25];
ll dp[2097157];
bool vis[2097157];
int n;

ll rec( int mask )
{
    if( vis[mask] )
        return dp[mask];

    for( int i=1; i<=n; i++ )
        for( int x=1; x<=n; j++ )
        {

        }
}

int main()
{
    cin>>n;

    for( int i=1; i<=n; i++ )
        for( int j=1; j<=n; j++ )
            cin>> mat[i][j];


}
