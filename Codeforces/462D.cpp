#include<bits/stdc++.h>
#define mx 100007
#define mod 1000000007
#define ll long long
using namespace std;

vector<int>adj[mx];
int col[mx];

ll dp[mx][2];
/// dp[u][0]-> ways to combine nodes in the subtree rooted at u such that there's no black node
/// dp[u][1]-> ways to combine nodes in the subtree rooted at u such that there's 1 black node

void dfs( int u, int p )
{
    if( col[u] )
        dp[u][1]++;
    else
        dp[u][0]++;

    for( auto v: adj[u] )
    {
        if(v==p)
            continue;

        dfs( v, u );

        if(!col[u])
        {
            dp[u][1]= ( dp[u][1]+dp[u][1]*dp[v][0] )%mod;
            dp[u][1]= ( dp[u][1]+(dp[u][0]*dp[v][1])%mod )%mod;
            dp[u][0]= ( dp[u][0]+dp[v][0] )%mod;
        }
        else
        {
            dp[u][1]= ( dp[u][1]*dp[v][0] )%mod;
            dp[u][1]= ( dp[u][1]+dp[v][1] )%mod;
            dp[u][0]= ( dp[u][0]+dp[v][0] )%mod;
        }
    }

    cout<<" "<<u<<" "<<dp[u][0]<<" "<<dp[u][1]<<endl;
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<n;i++ )
    {
        int p;
        cin>>p;

        adj[p].push_back(i);
    }

    for( int i=0;i<n;i++ )
        cin>> col[i];

    dfs(0,0);

    cout<< dp[0][1] <<endl;
}

