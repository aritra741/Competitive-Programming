#include<bits/stdc++.h>
using namespace std;

int n;
int dp[107][100007];
int arr[107];

int ans= 0;

void rec( int i, int x )
{
    if( i>=n )
    {
        dp[i][x]= 1;
        return;
    }

    if( dp[i][x]!=-1 )
        return;

    dp[i][x]= 1;

    rec( i+1, x );
    rec( i+1, x+arr[i] );
}

int main()
{
    memset( dp, -1, sizeof(dp) );
    cin>>n;

    for( int i=0; i<n; i++ )
        cin>>arr[i];

    rec( 0, 0 );

    vector<int>v;

    for( int i=1; i<=100000; i++ )
        for( int j=0; j<=n; j++ )
        {
            if( dp[j][i]==1 )
            {
                v.push_back(i);
                break;
            }
        }

    cout<< v.size() <<endl;

    for( auto x: v )
        cout<<x<<" ";
}
