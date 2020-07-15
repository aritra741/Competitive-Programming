#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;

vector<int> dv[2010];
int dp[2010][2010];

void init( int n, int K )
{
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
            dv[j].push_back(i);

    for(int i=1;i<=n;i++)
        dp[1][i]= 1;
}

int main()
{
    int n,K;
    cin>>n>>K;

    init(n,K);

    for(int i=2;i<=K;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<dv[j].size();k++)
                dp[i][j]= ( dp[i][j]+dp[i-1][dv[j][k]] )%m;

    int ans= 0;

    for(int i=1;i<=n;i++)
        ans= (ans+dp[K][i])%m;

    cout<< ans <<endl;
}
