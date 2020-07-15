#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n,k,d;

ll dp[107][107][2];
bool vis[107][107][2];

ll rec( int i, int tot, bool nisi )
{
    if( tot>n )
        return 0;
    if( tot==n )
    {
        if(nisi)
            return 1;
        return 0;
    }

    if( vis[i][tot][nisi] )
        return dp[i][tot][nisi];

    ll ret= 0;
    for( int j=1;j<=k;j++ )
    {
        bool now= nisi;

        if(j>=d)
            now= 1;

        ret= ( ret+ rec( j, tot+j, now ) )%mod;
    }

    vis[i][tot][nisi]= 1;

    return dp[i][tot][nisi]= ret;
}

int main()
{
    cin>>n>>k>>d;

    cout<< rec( 0, 0, 0 ) <<endl;
}
