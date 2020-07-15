#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mx 100007
using namespace std;

int par[mx], Size[mx];

ll bigmod( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= ( res*x )%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res%mod;
}

int Find( int u )
{
    if( u==par[u] )
        return u;
    return par[u]= Find( par[u] );
}

void Union( int u, int v )
{
    int paru= Find(u);
    int parv= Find(v);

    if( paru!=parv )
    {
        if( Size[paru]>Size[parv] )
            Size[paru]+= Size[parv], par[parv]= paru;
        else
            Size[parv]+= Size[paru], par[paru]= parv;
    }
}

int main()
{
    int n,k;
    cin>>n>>k;

    for( int i=1;i<=n;i++ )
        par[i]= i, Size[i]= 1;

    for( int i=1;i<n;i++ )
    {
        int p,q;
        cin>>p>>q;

        int w;
        cin>>w;

        if(!w)
            Union( p,q );
    }

    ll baad= 0;

    for( int i=1;i<=n;i++ )
        if( Find(i)==i )
            baad= (baad+bigmod( Size[ Find(i) ], k ))%mod;

    cout<< (bigmod( n,k )-baad+mod)%mod <<endl;
}
