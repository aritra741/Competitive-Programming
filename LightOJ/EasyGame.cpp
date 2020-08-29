#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int dp[110][110];
int vis[110][110];
int arr[110];
int n,p;

int rec( int i, int j )
{
    if(i>j)
        return 0;
    if( vis[i][j]==p )
        return dp[i][j];

    int q1= -inf;
    int tmp= 0;

    for(int l=i; l<=j; l++)
        tmp+= arr[l],
              q1= max( q1, tmp-rec( l+1, j ) );

    tmp= 0;
    for(int l=j; l>=i; l--)
        tmp+= arr[l],
              q1= max( q1, tmp-rec( i, l-1 ) );

    vis[i][j]= p;

    return dp[i][j]= q1;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        p++;
        cin>>n;

        for(int i=0; i<n; i++)
            cin>>arr[i];

        cout<<"Case "<<t<<": "<< rec( 0, n-1 ) <<endl;
    }
}
