#include<bits/stdc++.h>
#define mx 107
using namespace std;

vector<int>adj[mx], cost[mx];

int dp[107][107];
bool vis[107][107];

int rec( int u, int rakhbo, int p, int c )
{
//    cout<<u<<" "<<rakhbo<<" "<<p<<" "<<c<<endl;
    if( !rakhbo )
        return c;

    if( adj[u].size()==1 )
        return 0;

    if( vis[u][rakhbo] )
        return dp[u][rakhbo];

    int l_child, r_child, l_cost, r_cost;
    bool f= 0;

    for( int i=0;i<adj[u].size();i++ )
    {
        int w= cost[u][i];
        int v= adj[u][i];

        if(v==p)
            continue;

        if(!f)
            l_cost= w, l_child= v, f= 1;
        else
            r_cost=w, r_child= v;
    }

    int ret= 0;

    for( int i=0;i<rakhbo-1;i++ )
        if( rakhbo>1 )
            ret= max( ret, rec( l_child, i, u, l_cost )+rec( r_child, rakhbo-2-i, u, r_cost ) );

    ret= max( ret, rec( l_child, rakhbo-1, u, l_cost ) );
    ret= max( ret, rec( r_child, rakhbo-1, u, r_cost ) );

    vis[u][rakhbo]= 1;

    return dp[u][rakhbo]= ret+c;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for( int i=1;i<n;i++ )
    {
        int p,q,w;
        cin>>p>>q>>w;

        adj[p].push_back(q);
        adj[q].push_back(p);

        cost[p].push_back(w);
        cost[q].push_back(w);
    }

    cout<< rec( 1, m, 1, 0 ) <<endl;
}
