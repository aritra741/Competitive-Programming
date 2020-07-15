#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int dp[25][3];
int vis[25][3];
int arr[25][3];
int n, p;

int rec( int i, int col )
{
    if(i>=n)
        return 0;
    if( vis[i][col]==p )
        return dp[i][col];

    int q1= inf, q2= inf, q3= inf;

    if( col!=0 )
        q1= arr[i][0]+rec( i+1, 0 );
    if( col!=1 )
        q2= arr[i][1]+rec( i+1, 1 );
    if( col!=2 )
        q3= arr[i][2]+rec( i+1, 2 );

    vis[i][col]= p;

    return dp[i][col]= min( q1, min( q2,q3 ) );
}


int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        p++;
        cin>>n;
        cout<<"Case "<<t<<": ";

        for(int i=0;i<n;i++)
            for(int j=0;j<3;j++)
                cin>>arr[i][j];

        cout<< rec( 0, -1 ) <<endl;
    }
}
