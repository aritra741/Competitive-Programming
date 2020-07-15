#include<bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

int arr[100007];
ll freq[100007];
ll dp[25][100007];
ll cnt;
int l= 1, r;

ll kaj( int ql, int qr )
{
    while(l>ql)
    {
        l--;
        freq[ arr[l] ]++;
        cnt+= freq[ arr[l] ]-1;
    }
    while(r<qr)
    {
        r++;
        freq[ arr[r] ]++;
        cnt+= freq[ arr[r] ]-1;
    }
    while(l<ql)
    {
        cnt-= freq[ arr[l] ]-1;
        freq[ arr[l] ]--;
        l++;
    }
    while(r>qr)
    {
        cnt-= freq[ arr[r] ]-1;
        freq[ arr[r] ]--;
        r--;
    }
    return cnt;
}

void rec( int k, int l, int r, int p1, int p2 )
{
    if( r<l )
        return;

    p1= min( r, p1 );
    p2= max( 0, p2 );

    int mid= (l+r)/2;
    int opt= mid-1;

    dp[k][mid]= inf;

    for( int i=min( mid,p2 );i>=p1;i-- )
        if( dp[k][mid]>=dp[k-1][i]+kaj( i+1, mid ) )
            dp[k][mid]= dp[k-1][i]+kaj( i+1, mid ), opt= i;

    rec( k, l, mid-1, p1, opt );
    rec( k, mid+1, r, opt, p2 );
}

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    for( int i=1;i<=n;i++ )
        scanf("%d", &arr[i]);

    for( int i=1;i<=n;i++ )
        dp[1][i]= kaj( 1, i );

    for( int i=2;i<=k;i++ )
        rec( i, 1, n, 1, n );

    printf("%lld\n", dp[k][n]);
}
