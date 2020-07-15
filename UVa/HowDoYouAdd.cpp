#include <bits/stdc++.h>
#define ll long long
#define m 1000000
using namespace std;

int dp[110][110];
bool vis[110][110];

int rec( int n, int k )
{
    if(k==1)
        return 1;
    if(vis[n][k])
        return dp[n][k];

    int q= 0;

    for(int i=0;i<=n;i++)
        q= ((q%m)+rec( n-i, k-1 )%m)%m;

    vis[n][k]= 1;

    return dp[n][k]= q%m;
}

int main()
{
    while(1)
    {
        int n, k;
        cin>>n>>k;

        if(!n and !k)
            break;

        cout<< rec(n,k) <<endl;
    }
}
