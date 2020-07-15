#include <bits/stdc++.h>
using namespace std;

int dp[10010][2], vis[10010][2];
int arr[2][10010];
int n,m,p;
map<int,int> mp, mp2;

int rec( int i, int a )
{
    if( !a and i>=n )
        return 0;
    if( a and i>=m )
        return 0;

    if( vis[i][a]==p )
        return dp[i][a];

    int q1= -2e9, q2= -2e9;

    q1= arr[a][i]+rec( i+1, a );

    if( a and mp[arr[a][i]] )
        q2= arr[a][i]+rec( mp[arr[a][i]]+1, !a );

    else if( !a and mp2[arr[a][i]] )
        q2= arr[a][i]+rec( mp2[arr[a][i]]+1, !a );

    vis[i][a]= p;

    return dp[i][a]= max( q1, q2 );
}

int main()
{
    while(1)
    {
        p++;

        scanf("%d", &n);

        if(!n)
            break;

        for( int i=0; i<n; i++ )
            scanf("%d", &arr[0][i]), mp[arr[0][i]]= i;

        scanf("%d", &m);

        for( int i=0; i<m; i++ )
            scanf("%d", &arr[1][i]), mp2[arr[1][i]]= i;

        cout<< max( rec( 0,0 ), rec( 0,1 ) ) <<endl;

        mp.clear();
        mp2.clear();
    }
}
