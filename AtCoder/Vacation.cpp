#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[100007][3];
ll dp[100007][3];
bool vis[100007][3];
int n;

ll rec( int i, int prev  )
{
    if(i>=n)
        return 0;
    if(vis[i][prev])
        return dp[i][prev];

    ll ans= 0;
    for(int j=0;j<3;j++)
    {
        if(prev==j)
            continue;
        ans= max( ans, arr[i][j]+rec(i+1,j) );
    }

    vis[i][prev]= 1;

    return dp[i][prev]= ans;
}

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>arr[i][j];

    cout<< rec( 0, -1 ) <<endl;
}
