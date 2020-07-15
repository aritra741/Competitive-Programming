#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,b,mod;

int arr[510];
int dp[510][510];
bool vis[510][510];

int main()
{
    cin>>n>>m>>b>>mod;

    dp[0][0]= 1%mod;

    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];

        for(int j=1;j<=m;j++)
            for(int k=arr[i];k<=b;k++)
                dp[j][k]= ( dp[j][k]+dp[j-1][k-arr[i]] )%mod;
    }

    int ans= 0;

    for(int i=0;i<=b;i++)
        ans= (ans+dp[m][i])%mod;

    cout<< ans <<endl;
}
