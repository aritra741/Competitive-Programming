#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[]={1,5,10,25,50};
ll dp[10][7500];
bool vis[10][7500];
int cap;

ll recur( int i, int curr )
{
    if(i>5)
        return 0;
    if(curr==0)
        return 1;
    cout<<arr[i-1]<<" "<<curr<<endl;
    if(vis[i][curr])
        return dp[i][curr];

    ll p1=0,p2;

    if(curr-arr[i-1]>=0)
        p1= recur( i, curr-arr[i-1] );
    p2=recur( i+1, curr );

    vis[i][curr]=1;

    return dp[i][curr]= p1+p2;
}

int main()
{
   // recur(1, 7489);
    while(scanf("%d", &cap)==1)
    {
        printf("%lld\n", recur( 1, cap ));
    }
}
