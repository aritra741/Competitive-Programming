#include <bits/stdc++.h>
using namespace std;

int dp[52][1010];
bool vis[52][1010];
int w[52], Val[52];
int cap, n;

int rec( int i, int weight )
{
    if(i>=n)
        return 0;

    if(vis[i][weight])
        return dp[i][weight];

    int q1= ( weight+w[i]<=cap )?Val[i]+rec( i+1, weight+w[i]):0;
    int q2= rec(i+1, weight);

    vis[i][weight]= 1;

    return dp[i][weight]= max(q1,q2);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>cap>>n;

        for(int i=0;i<n;i++)
            cin>>w[i]>>Val[i];

        cout<<"Hey stupid robber, you can get "<<rec( 0, 0 )<<"." <<endl;

        memset(vis, 0, sizeof(vis));
    }
}
