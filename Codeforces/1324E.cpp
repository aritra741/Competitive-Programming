#include<bits/stdc++.h>
using namespace std;

int n,h,l,r;
int arr[2007];
int dp[2007][2007];
bool vis[2007][2007];

int rec( int i, int hh )
{
    if( i>=n )
        return 0;
    if( vis[i][hh] )
        return dp[i][hh];

    int q1, q2;

    q1= rec( i+1, (hh+arr[i]-1+h)%h );

    if( (arr[i]-1+hh+h)%h>=l and (arr[i]-1+hh+h)%h<=r )
        q1++;

    q2= rec( i+1, (hh+arr[i]+h)%h );

    if( (arr[i]+hh+h)%h>=l and (arr[i]+hh+h)%h<=r )
        q2++;

    vis[i][hh]= 1;

    return dp[i][hh]= max( q1, q2 );
}

int main()
{
    cin>>n>>h>>l>>r;

    for(int i=0;i<n;i++)
        cin>> arr[i];

    cout<< rec( 0, 0 ) <<endl;
}
