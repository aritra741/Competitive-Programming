#include<bits/stdc++.h>
#define ll long long
#define mx 100007
#define mod 1000000007
using namespace std;

vector<int>adj[mx];

ll dp[mx][2][2];
bool vis[mx][2][2];

ll rec( int node, int p, int idx, bool col, bool same )
{
    int u= adj[node][idx];

    cout<<u<<":\n";

    if( adj[u].size()==1 )
    {
        if( idx+1<adj[node].size() )
            return rec( node, p, idx+1, col, same );
        return same;
    }

    if( u==p )
    {
        if( idx+1<adj[node].size() )
            return rec( node, p, idx+1, col, same );
        return 1LL;
    }

    if( vis[u][col][same] )
        return dp[u][col][same];

    ll ret= 0;

    ll q1= rec( u, node, 0, col, 1 );

    if( idx+1<adj[node].size() )
        q1= ( q1*rec( node, p, idx+1, col, same ) )%mod;

    ll q2= rec( u, node, 0, !col, 0 );

    if( idx+1<adj[node].size() )
        q2= ( q2*rec( node, p, idx+1, col, same ) )%mod;

    vis[u][col][same]= 1;

    cout<<node<<" "<<col<<" "<<same<<" "<<q1+q2<<endl;

    return dp[u][col][same]= (q1+q2)%mod;
}

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<n;i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    cout<< (rec( 1, 1, 0, 0, 0 )*2LL)%mod <<endl;
}

