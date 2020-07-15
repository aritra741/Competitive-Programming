#include <bits/stdc++.h>
#define MX 2010
using namespace std;

int n, cap;
int dp[MX][MX];
bool vis[MX][MX];
int val[MX];

int rec(int i, int curr)
{
    if(i>n)
        return 0;
    if(vis[i][curr])
        return dp[i][curr];

    int p1,p2;

    if(val[i-1]+curr<=cap)
        p1= val[i-1]+rec( i, curr+val[i-1] );
    else
        p1=0;

    p2= rec(i+1, curr);

    vis[i][curr]=1;

    return dp[i][curr]= max(p1,p2);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n>>cap;

        for(int i=0;i<n;i++)
            cin>>val[i];

        cout<< rec(1,0) <<endl;

        memset(vis, 0, sizeof(vis));
    }
}
