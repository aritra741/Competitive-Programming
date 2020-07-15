#include<bits/stdc++.h>
#define inf 2e9
using namespace std;

int arr[35007];
int freq[35007];
int dp[55][35007];

int l=1,r;
int cnt;

int kaj( int ql, int qr )
{
    while(l>ql)
    {
        l--;
        freq[ arr[l] ]++;

        if( freq[ arr[l] ]==1 )
            cnt++;
    }
    while(r<qr)
    {
        r++;
        freq[ arr[r] ]++;

        if( freq[ arr[r] ]==1 )
            cnt++;
    }
    while(l<ql)
    {
        freq[ arr[l] ]--;
        if( arr[l] and !freq[ arr[l] ] )
            cnt--;
        l++;
    }
    while(r>qr)
    {
        freq[ arr[r] ]--;
        if( arr[r] and !freq[ arr[r] ] )
            cnt--;
        r--;
    }
    return cnt;
}

void rec( int k, int l, int r, int p1, int p2 )
{
    if( r<l )
        return;

    p1= min( p1, r );
    p2= max( 0, p2 );

    int mid= (l+r)/2;
    int opt= mid-1;

    dp[k][mid]= -inf;

    for( int i=min( mid, p2 ); i>=p1; i-- )
        if( dp[k][mid]<=dp[k-1][i]+kaj( i+1, mid ) )
            dp[k][mid]= dp[k-1][i]+kaj( i+1, mid ), opt= i;

    rec( k, l, mid-1, p1, opt );
    rec( k, mid+1, r, opt, p2 );
}

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    for( int i=1; i<=n; i++ )
    {
        scanf("%d", &arr[i]);
        dp[1][i]= kaj( 1, i );
    }

    for( int i=2;i<=k;i++ )
        rec( i, 1, n, 1, n );

    printf("%d\n", dp[k][n] );
}
