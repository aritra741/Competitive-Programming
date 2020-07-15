#include <bits/stdc++.h>
#define m 1000000007
#define mx 100007
#define ll long long
using namespace std;

ll cumsum[mx];
ll dp[mx];

int main()
{
    int n,k;
    cin>>n>>k;

    dp[0]= 1;
    dp[1]= 1+ (k==1);

    for(int i=2; i<mx; i++)
    {
        dp[i]=dp[i-1]%m;

        if(i-k>=0)
            dp[i]=(dp[i]+dp[i-k])%m;
        }

    for(int i=1; i<mx; i++)
        cumsum[i]= (cumsum[i-1]+dp[i])%m;

    while(n--)
    {
        ll r, l;
        cin>>l>>r;

        cout<< ( cumsum[r]-cumsum[l-1]+m )%m <<endl;
    }
}



