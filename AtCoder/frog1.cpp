#include <bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

ll dp[100007];
ll vis[100007];
ll arr[100007];
int n;

ll rec( int now )
{
    if(now>=n)
        return inf;
    if(now==n-1)
        return 0;
    if(vis[now])
        return dp[now];

    ll q1=  llabs(arr[ now+1 ]-arr[ now ])+rec(now+1);
    ll q2=  llabs(arr[ now+2 ]-arr[ now ])+rec(now+2);

    vis[now]= 1;

    return dp[now]= min( q1,q2 );
}

int main()
{
   cin>>n;

   for(int i=0;i<n;i++)
        cin>>arr[i];

   cout<< rec( 0 ) <<endl;
}
