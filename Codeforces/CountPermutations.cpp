#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[32770][16][2];
int vis[32770][16][2];
int p,n,k,done;

ll rec( int mask, int prev, bool valid )
{
    if(mask==done)
    {
        if(valid)
            return 1LL;
        return 0;
    }

    if( vis[mask][prev][valid]==p )
        return dp[mask][prev][valid];

    ll ans= 0;
    int i= __builtin_popcount(mask);

    for(int j=0;j<n;j++)
    {
        if( mask&(1<<j) )
            continue;
        bool now= valid;

        if( !i or abs(j+1-prev)<=k );
        else
            now= 0;

        ans+= rec( mask|(1<<j), j+1, now );
    }

    vis[mask][prev][valid]= p;

    return dp[mask][prev][valid]= ans;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        p++;
        cin>>n>>k;
        done= (1<<n)-1;
        string s;
        cout<< rec( 0, 0, 1 ) <<endl;
    }
}
