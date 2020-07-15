#include<bits/stdc++.h>
#define mx 100007
using namespace std;

int arr[107];
int dp[mx];
bool vis[mx];
int n,k;

/// dp[i]= TRUE if it's a wining state for the first player

int main()
{
    cin>>n>>k;

    for( int i=0;i<n;i++ )
        cin>> arr[i];

    for( int stones= 0;stones<=k;stones++ )
        for( int i=0;i<n;i++ )
            if( stones-arr[i]>=0 and !dp[stones-arr[i]] )
                dp[stones]= 1;

    if( dp[k] )
        cout<<"First\n";
    else
        cout<<"Second\n";
}
