#include<bits/stdc++.h>
using namespace std;

bool dp[35][250];
bool vis[35][250];
int shuru[35], shesh[35];
int n,d;

bool rec( int i, int num )
{
    if(i>=n)
    {
        if( num )
            return 0;
        return 1;
    }

    if(vis[i][num])
        return dp[i][num];

    bool ret= 0;
    for( int j=shuru[i]; j<=shesh[i]; j++ )
        if( num-j>=0 )
            ret|= rec( i+1, num-j );

    vis[i][num]= 1;

    return dp[i][num]= ret;
}

int main()
{
    cin>>n>>d;

    for( int i=0; i<n; i++ )
        cin>>shuru[i]>>shesh[i];

    if( rec(0,d) )
    {
        cout<<"YES\n";

        int baki= d;
        for( int i=0; i<n; i++ )
            for( int j=shuru[i]; j<=shesh[i]; j++ )
                if( dp[i+1][baki-j] )
                {
                    cout<<j<<" ";
                    baki-= j;
                    break;
                }

        cout<<baki<<endl;
    }
    else
        cout<<"NO\n";
}
