#include <bits/stdc++.h>
#define mx 100007
#define ll long long
using namespace std;

int adj[mx];
bool vis[mx];
int cnt;
vector<int> scc;

void dfs( int u )
{
    vis[u]= 1;
    cnt++;

    if( !vis[adj[u]] )
        dfs( adj[u] );
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>> adj[i];

    for(int i=1;i<=n;i++)
    {
        if( vis[i] )
            continue;

        cnt= 0;
        dfs( i );
        scc.push_back(cnt);
    }

    sort( scc.begin(), scc.end(), greater<int>() );

    ll ans= 1;

    if( scc.size()==1 )
        ans= scc[0];
    else
        ans= scc[0]+scc[1];

    ll temp= ans;
    ans*= (ans-1);
    ans+= temp;

    for(int i=2;i<scc.size();i++)
        ans+= scc[i]*scc[i];

    cout<< ans <<endl;
}
