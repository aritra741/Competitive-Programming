#include <bits/stdc++.h>
#define ll long long

int arr[21];
ll dp[22][10007];
bool vis[22][10007];
int n;

void init()
{
    for(int i=1;i<=21;i++)
        arr[i-1]= i*i*i;
}

ll rec( int i, int curr )
{
    if(curr==0)
        return 1;
    if(i>21)
        return 0;
    if(vis[i][curr])
        return dp[i][curr];

    ll p1=0,p2;

    if(curr-arr[i-1]>=0)
        p1= rec( i, curr-arr[i-1] );
    p2= rec( i+1, curr);

    vis[i][curr]=1;

    return dp[i][curr]= p1+p2;

}

int main()
{
    init();
    rec(1, 9999);

    while( scanf("%d", &n)==1 )
    {
        printf("%lld\n", rec(1, n));
    }
}

