#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[]= {1,5,10,25,50};
ll dp[7490][5];
bool vis[7490][5];

int main()
{
    int n;

    for(int i=0; i<5; i++)
        dp[0][i]=1;

    for(int i=1; i<7490; i++)
        for(int j=0; j<5; j++)
        {
            ll incl= (i-arr[j]>=0)? dp[i-arr[j]][j]:0;
            ll excl= (j>=1)? dp[i][j-1]:0;

            dp[i][j]= incl+excl;
        }

    while(scanf("%d", &n)==1)
    {
        printf("%lld\n", dp[n][4]);
    }
}
