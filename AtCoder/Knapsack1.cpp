#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[107], weight[107];
ll dp[107][100007];
bool vis[107][100007];
ll W;
int n;

ll rec( int i, ll w )
{
    if(i>=n)
        return 0;
    if(vis[i][w])
        return dp[i][w];

    ll q1= rec( i+1, w );
    ll q2= 0;

    if( weight[i]+w<= W )
        q2= arr[i]+rec( i+1, w+weight[i] );

    vis[i][w]= 1;

    return dp[i][w]= max(q1,q2);
}

int main()
{
    cin>>n>>W;

    for(int i=0;i<n;i++)
        cin>>weight[i]>>arr[i];

    cout<< rec( 0, 0 ) <<endl;
}
