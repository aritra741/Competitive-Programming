#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[15],m,n;
ll dp[15][15];
int vis[15][15];
int p;

ll rec( int i, int cnt )
{
    if(cnt==n)
        return 1;
    if(i>m)
    {
        if(cnt==n-1)
            return 1;
        return 0;
    }

    if( vis[i][cnt]==p )
        return dp[i][cnt];

    ll q1= 0;

    for(int j=1; j<=m; j++)
        if( i==-1 or abs(arr[i]-arr[j])<=2 )
            q1+= rec( j, cnt+1 );


    vis[i][cnt]= p;

    return dp[i][cnt]= q1;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        p++;
        cin>>m>>n;

        for(int i=1; i<=m; i++)
            cin>>arr[i];

        cout<<"Case "<<t<<": "<< rec( -1, 0 ) <<endl;
    }
}
