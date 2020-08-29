#include<bits/stdc++.h>
#define ll long  long
using namespace std;

int arr[32];
ll dp[35][3][3][32];
int vis[35][3][3][32];
int pp;

void bin( int n )
{
    int i= 0;

    while(n)
        arr[i++]= n%2, n/= 2;
    for( int j=0; j<16; j++ )
        swap( arr[j], arr[32-j-1] );
}

ll rec( int i, bool last, bool small, int koto )
{
    if( i>=32 )
        return koto;
    if( vis[i][last][small][koto]==pp )
        return dp[i][last][small][koto];

    ll ret= 0;

    if( small )
    {
        ret+= rec( i+1, 0, 1, koto );

        if(last)
            ret+= rec( i+1, 1, 1, koto+1 );
        else
            ret+= rec( i+1, 1, 1, koto );
    }
    else
    {
        if( arr[i] )
        {
            ret+= rec( i+1, 0, 1, koto );

            if(last)
                ret+= rec( i+1, 1, small, koto+1 );
            else
                ret+= rec( i+1, 1, small, koto );
        }
        else
            ret+= rec( i+1, 0, small, koto );
    }

    vis[i][last][small][koto]= pp;

    return dp[i][last][small][koto]= ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        pp++;
        int n;
        scanf("%d", &n);

        memset( arr, 0, sizeof(arr) );
        bin(n);

        printf("Case %d: %lld\n", t, rec(0,0,0,0));
    }
}
