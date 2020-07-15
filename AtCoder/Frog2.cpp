#include <bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

ll dp[100007];
ll vis[100007];
ll arr[100007];
int n,k;

ll rec( int now )
{
    if(now>=n)
        return inf;
    if(now==n-1)
        return 0;
    if(vis[now])
        return dp[now];

    ll ans= inf;

    for(int i=1;i<=k;i++)
    {
        ans= min(ans,llabs(arr[ now+i ]-arr[ now ])+rec(now+i));
    }

    vis[now]= 1;

    return dp[now]= ans;
}

int main()
{
   cin>>n>>k;

   for(int i=0;i<n;i++)
        cin>>arr[i];

   cout<< rec( 0 ) <<endl;
}
