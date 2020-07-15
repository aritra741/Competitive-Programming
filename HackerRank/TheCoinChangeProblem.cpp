#include <bits/stdc++.h>
#define MX 300
#define ll long long
using namespace std;

ll dp[60][MX];
int val[60];
bool vis[60][MX];
int n,cap;

ll rec(int i, int curr)
{
    if(i>n)
        return 0;
    if(curr==cap)
        return 1;

    if(vis[i][curr])
        return dp[i][curr];

    ll p1,p2;

    if(val[i-1]+curr<=cap)
        p1= rec(i, curr+val[i-1]);
    else
        p1=0;
    p2= rec(i+1, curr);

    vis[i][curr]=1;

    return dp[i][curr]= p1+p2;

}

int main()
{
    cin>>cap>>n;

    for(int i=0;i<n;i++)
        cin>>val[i];

    cout<< rec(1, 0) <<endl;

    memset(vis, 0, sizeof(vis));

}
