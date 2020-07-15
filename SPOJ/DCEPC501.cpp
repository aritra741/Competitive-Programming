#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[100007], dp[100007], vis[100007];
int n,p;

ll rec( int i )
{
    if( i>=n )
        return 0;
    if( vis[i]==p )
        return dp[i];

    ll q1= 0;

    for( int j=i;j<min( n, i+3 );j++ )
        q1+= arr[j];
    q1+= rec( i+6 );

    ll q2= 0;

    for( int j=i;j<min( n, i+2 );j++ )
        q2+= arr[j];
    q2+= rec( i+4 );

    ll q3= arr[i]+rec( i+2 );

    vis[i]= p;

    return dp[i]= max( q1, max( q2, q3 ) );
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        p++;
        scanf("%d", &n);

        for( int i=0;i<n;i++ )
            scanf("%lld", &arr[i]);

        printf("%lld\n", rec( 0 ) );
    }
}
