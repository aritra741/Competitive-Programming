#include<bits/stdc++.h>
using namespace std;

double dp[100007];
int vis[100007];

int n,pp;

double rec( int i )
{
    if(i==n)
        return 0;
    if(vis[i]==pp)
        return dp[i];

    vis[i]= pp;
    return dp[i]= ( n+(n-i)*rec(i+1) )/(n-i);
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        pp++;
        scanf("%d", &n);

        printf("Case %d: %.10f\n", t, rec(0));
    }
}
