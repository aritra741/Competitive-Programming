#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1007];
bool vis[1007];
ll n, val[1007];

ll rec( int i )
{
    if(i>=n)
        return 0;
    if(vis[i])
        return dp[i];

    ll q1= val[i]+ rec(i+2);
    ll q2= rec(i+1);

    vis[i]= 1;

    return dp[i]= max(q1,q2);
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        cin>>n;

        for(int i=0;i<n;i++)
            cin>>val[i];

        ll ans= rec( 0 );

        cout<<"Case "<<t<<": "<< ans <<endl;

        memset(vis,0,sizeof(vis));
    }
}
