#include <bits/stdc++.h>
using namespace std;

int arr[1010];
int dp[1010][2][2];
int vis[1010][2][2];
int n,p;

int rec( int i, bool one, bool N )
{
    if( i>n )
        return 0;

    if( vis[i][one][N]==p )
        return dp[i][one][N];

    int q1;

    if( i==n and one )
        q1= 0;
    else
    {
        int tempOne= one, tempN= N;
        if(i==n)
            tempN= 1;
        else if(i==1)
            tempOne= 1;
        q1= arr[i]+rec( i+2, tempOne, tempN );
    }

    int q2= rec(i+1,one,N);

    vis[i][one][N]= p;

    return dp[i][one][N]= max(q1,q2);
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        p++;
        scanf("%d", &n);

        for(int i=1; i<=n; i++)
            scanf("%d", &arr[i]);

        printf("Case %d: %d\n", t, rec( 1,0,0 ));
    }
}
