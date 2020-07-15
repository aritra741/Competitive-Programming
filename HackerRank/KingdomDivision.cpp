#include<bits/stdc++.h>
#define ll long long
#define mx 100007
#define mod 1000000007
using namespace std;

vector<int>adj[mx];

ll dp[mx][2][2];
bool vis[mx][2][2];

ll rec( int u, int p, bool col, bool same )
{
    ll shada= 1, kalo= 1, total= 1;

    if( vis[u][col][same] )
        return dp[u][col][same];

    for( auto v: adj[u] )
    {
        if( v==p )
            continue;

        ll q1= rec( v, u, 0, col==0 );
        ll q2= rec( v, u, 1, col==1 );

        shada= ( shada*q1 )%mod;
        kalo= ( kalo*q2 )%mod;

        total= ( total*(( q1+q2 )%mod) )%mod;
    }

    if( col and !same )
        total= ( total-shada+mod )%mod;
    else if( !col and !same )
        total= ( total-kalo+mod )%mod;

    vis[u][col][same]= 1;
//
//    cout<<u<<" "<<col<<" "<<same<<"     "<<shada<<" "<<kalo<<endl;

    return dp[u][col][same]= total;
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

    cout<< (rec( 1, 1, 0, 0 )*2LL)%mod <<endl;
}

