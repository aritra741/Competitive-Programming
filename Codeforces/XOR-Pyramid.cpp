#include <bits/stdc++.h>
using namespace std;

int dp[5007][5007], mx[5007][5007];

int rec( int l, int r )
{
    if( l==r )
        return dp[l][l];

    int &ret= dp[l][r];

    if( ret!=-1 )
        return ret;
    return ret= rec( l+1, r )^rec( l, r-1 );        ///https://codeforces.com/blog/entry/59484?#comment-431290
}

int query( int l, int r )
{
    int &ans= mx[l][r];

    if(ans!=-1)
        return mx[l][r];

    return ans= max( rec( l,r ), max( query(l+1,r), query(l,r-1) ) );
}

int main()
{
    memset(mx, -1, sizeof(mx));
    memset(dp, -1, sizeof(dp));

    int n;
    scanf("%d", &n);

    for( int i=1;i<=n;i++ )
    {
        int p;
        scanf("%d", &p);
        dp[i][i]= p;
        mx[i][i]= p;
    }

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);

        int out= query( l, r );

        printf("%d\n", out);
    }
}
