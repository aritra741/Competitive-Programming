#include<bits/stdc++.h>
#define ll long long
#define mx 200007
using namespace std;

ll cost;
ll ans[mx];
ll sum[mx], dp[mx];
int arr[mx];
vector<int>adj[mx];

void dfs( int u, int pre, int lvl )
{
    sum[u]= arr[u];
    for( auto v: adj[u] )
    {
        if(v==pre)
            continue;
        dp[u]+= (ll)arr[v]*(lvl+1);
        dfs( v, u, lvl+1 );
        dp[u]+= dp[v];
        sum[u]+= sum[v];
    }
}

void dfs2( int u, int pre )
{
    ll tmp= ans[pre];
    ll agey= sum[pre];

    if(u!=pre)
        tmp-= sum[u],
        sum[pre]-= sum[u],
        sum[u]+= sum[pre],
        tmp+= sum[pre],
        sum[pre]= agey;

    ans[u]= tmp;
    cost= max( cost, tmp );

    for( auto x: adj[u] )
    {
        if(x==pre)
            continue;
        dfs2( x, u );
    }
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
        cin>>arr[i];

    for( int i=1;i<n;i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    dfs(1,0,0);
    ans[1]= dp[1];
    dfs2(1,1);

    cout<< cost <<endl;
}
