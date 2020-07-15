#include <bits/stdc++.h>
using namespace std;

int dp[21][5000];
bool vis[21][5000];
vector<int> v[21];
int m,n;

int rec( int i, int tot )
{
    if(i>=n)
    {
        if(tot<0)
            return INT_MIN;
        return 0;
    }

    if(vis[i][tot])
        return dp[i][tot];

    int q1= INT_MIN;

    for(int j=0; j<v[i].size(); j++)
    {
        int temp;
        temp=v[i][j]+rec( i+1, tot-v[i][j] );
        q1= max( q1, temp );
    }

    vis[i][tot]= 1;

    return dp[i][tot]= q1;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>m>>n;

        for(int i=0; i<n; i++)
        {
            int p;
            cin>>p;

            for(int j=0; j<p; j++)
            {
                int q;
                cin>>q;
                v[i].push_back(q);
            }
        }

        rec(0,m);

        if(dp[0][m]<0)
            cout<<"no solution\n";
        else
            cout<< dp[0][m] <<endl;

        memset( vis, 0, sizeof(vis) );

        for(int i=0;i<n;i++)
            v[i].clear();

    }
}
