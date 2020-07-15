#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt[100005]= {0};
ll dp[100005]= {0};

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        cnt[p]++;
    }

    dp[0]=0;
    dp[1]=cnt[1];

    for(int i=2;i<=100005;i++)
        dp[i]= max( dp[i-2] + cnt[i]*i, dp[i-1] );
    cout<<dp[100005];



}

