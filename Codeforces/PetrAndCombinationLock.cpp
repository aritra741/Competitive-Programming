#include <bits/stdc++.h>
using namespace std;

bool dp[32800][3000];
bool vis[32800][3000];
int n, done, arr[20];

bool rec( int mask, int now )
{
    if(mask==done)
    {
        if(now%360)
            return 0;
        return 1;
    }
    if(vis[mask][now])
        return dp[mask][now];

    bool q1= 0;
    bool q2= 0;

    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
            continue;
        q1= rec( mask|(1<<i), now+arr[i] );
        q2= rec( mask|(1<<i), now-arr[i] );
    }

    vis[mask][now]= 1;

    return dp[mask][now]= q1|q2;
}

int main()
{
    cin>>n;
    done= (1<<n)-1;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    bool ans= rec(0,0);

    if(ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
