#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int n,l,c;
int arr[1007];
pii dp[1007][1007];
int vis[1007][1007];
int pp;

int cost( int t )
{
    if(!t)
        return 0;
    if( t<=10 )
        return -c;
    return ( t-10 )*( t-10 );
}

pii rec( int i, int j, int rem )
{
    if( i>=n )
        return pii(0,cost(rem));
    if( vis[i][j][rem]==pp )
        return dp[i][j][rem];

    pii ret= {2e9,2e9};

    if( rem-arr[i]>=0 )
        ret= rec( i+1, j, rem-arr[i] );

    pii q= rec( i, j+1, 500 );
    q.ff++;
    q.ss+= cost(rem);

    vis[i][j][rem]= pp;

    dp[i][j][rem].ff= min( ret.ff, q.ff );
    dp[i][j][rem].ss= min( ret.ss, q.ss );

    return dp[i][j][rem];
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        scanf("%d", &n);
        scanf("%d %d", &l, &c);

        pp++;

        for( int i=0;i<n;i++ )
            scanf("%d", &arr[i]);

        printf("%d %d\n", rec( 0, 0, 500 ).ff, rec( 0, 0, 500 ).ss );
    }
}
