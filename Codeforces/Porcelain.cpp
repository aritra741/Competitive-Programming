#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[110][110][110], dp2[110][10007], best[110][110];
int vis[110][110][110], vis2[110][10007], q[110];
int arr[110][110], row, n, m, p;

ll rec( int l, int r, int rem )
{
    if( !rem or l>r )
        return 0;
    if( vis[l][r][rem]==p )
        return dp[l][r][rem];

    ll ans= -1;

    ans= arr[row][l]+rec( l+1, r, rem-1 );
    ans= max( ans, arr[row][r]+rec( l, r-1, rem-1 ) );

    vis[l][r][rem]= p;

    return dp[l][r][rem]= ans;
}

ll rec2( int row, int rem )
{
    if( row>=n )
        return 0;
    if( rem<=0 )
        return 0;
    if( vis2[row][rem] )
        return dp2[row][rem];

    ll ans= -1;

    for( int i=0; i<=q[row]; i++ )
        if(i<=rem)
            ans= max( ans, best[row][i]+rec2( row+1, rem-i ) );

    vis2[row][rem]= 1;

    return dp2[row][rem]= ans;
}

int main()
{
    cin>>n>>m;

    for( int i=0; i<n; i++ )
    {
        cin>>q[i];

        for( int j=0; j<q[i]; j++ )
            cin>> arr[i][j];
    }

    for( int i=0; i<n; i++ )
    {
        row= i;
        p++;
        for( int j=0; j<=q[i]; j++ )
            best[i][j]= rec( 0, q[i]-1, j );
    }

    cout<< rec2( 0, m ) <<endl;
}
