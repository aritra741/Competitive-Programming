#include <bits/stdc++.h>
using namespace std;


bool dp[30][30][30][30];
int arr[30][30];

int main()
{
    int n,m;
    cin>>n>>m;

    for( int i=0;i<n;i++ )
        for( int j=0;j<n;j++ )
            cin>> arr[i][j];

    for( int i=0;i<n;i++ )
        dp[0][i][0][i]=
}
