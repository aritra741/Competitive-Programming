#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool dp[1007][1007][2];
bool vis[1007][1007][2];
int arr[1000007];
int n,m;

bool rec( int i, int mod, bool taken )
{
    if(mod==0)
        return 1;
    if(i>=n)
        return 0;
    if(vis[i][mod][taken])
        return dp[i][mod][taken];

    bool q1= 0;
    if(i!=n-1)
        q1= rec( i+1, (mod-arr[i]+m)%m, taken );
    else if(taken)
        q1= rec( i+1, (mod-arr[i]+m)%m, taken );
    bool q2= rec( i+1, mod, 1 );

    vis[i][mod][taken]= 1;

    return dp[i][mod][taken]= q1|q2;
}

int main()
{
    cin>>n>>m;

    if(n>m)
    {
        cout<<"YES\n";
        return 0;
    }

    ll tot= 0;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        tot+=arr[i];
    }

    int ans= rec( 0, tot%m, 0 );

    if(ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
