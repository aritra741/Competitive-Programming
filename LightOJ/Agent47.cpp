#include <bits/stdc++.h>
#define inf 1e8
#define ll long long
using namespace std;

ll dp[32800][17];
bool vis[32800][17];
int arr[20][20], health[20];
int done, n;

ll rec( int mask, int now )
{
    //cout<<__builtin_popcount(mask)<<" "<<now<<endl;
    if(done==mask)
        return 0;
    if(vis[mask][now])
        return dp[mask][now];

    ll ans= inf;

    for(int j=0; j<n; j++)
    {
        if( mask&(1<<j) )
            continue;
        int mx= 1;

        for(int i=0; i<n; i++)
        {
            if(!(mask&(1<<i)))
                continue;
            mx= max(mx, arr[i][j]);
        }

       // cout<<j<<" "<<mx<<endl;
        ll shot= (health[j]+mx-1)/mx;
        ll q= shot+rec( mask|(1<<j), j);
        ans=min(ans,q);
    }

    vis[mask][now]= 1;

    return dp[mask][now]= ans;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        cin>>n;

        done= (1<<n)-1;

        for(int i=0; i<n; i++)
            cin>>health[i];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                char c;
                cin>>c;
                arr[i][j]= c-'0';
            }

        cout<<"Case "<<t<<": "<< rec( 0, 0 ) <<endl;

        memset(vis,0,sizeof(vis));
    }
}
