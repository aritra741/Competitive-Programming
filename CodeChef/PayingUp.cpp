#include <bits/stdc++.h>
using namespace std;

int arr[110];
int dp[110][20007];
bool vis[110][20007];

int n,m;

bool rec( int i, int tot )
{
    if(tot<0)
        return 0;
    if(tot==0)
        return 1;
    if(i>=n)
        return 0;
    if( vis[i][tot] )
        return dp[i][tot];

    bool q1= rec( i+1, tot );
    bool q2= rec( i+1, tot-arr[i] );

    return dp[i][tot]= q1 or q2;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n>>m;

        for(int i=0; i<n; i++)
            cin>>arr[i];

        if(m>20000)
            cout<<"No\n";
        if( rec( 0, m ) )
            cout<<"Yes\n";
        else
            cout<<"No\n";

        memset( vis, 0, sizeof(vis) );
    }
}
