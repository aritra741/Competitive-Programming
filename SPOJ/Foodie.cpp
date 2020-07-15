#include <bits/stdc++.h>
using namespace std;

int dp[12][10007];
bool vis[12][10007];
int arr[12];
int cap, n;

int rec( int i, int curr )
{
    if(i>=n)
    {
        if(curr<=cap)
            return curr;
        return 0;
    }

    if(vis[i][curr])
        return dp[i][curr];

    int q1= rec(i+1, curr+arr[i]);
    int q2= rec(i+1, curr);

    vis[i][curr]= 1;

    return dp[i][curr]= max(q1,q2);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n>>cap;

        for(int i=0;i<n;i++)
        {
            int p, q, tot= 0;;
            cin>>p;

            for(int j=0;j<p;j++)
            {
                cin>>q;
                tot+=q;
            }

            arr[i]= tot;
        }

        cout<< rec(0, 0) <<endl;

        memset(vis,0, sizeof(vis));
    }
}
