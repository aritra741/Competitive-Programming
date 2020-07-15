#include <bits/stdc++.h>
#define mx 10007
using namespace std;

int par[mx], Size[mx];

int Find( int u )
{
    if( par[u]==u )
        return u;
    return par[u]= Find(par[u]);
}

void unite( int u, int v )
{
    int paru= Find( u );
    int parv= Find( v );

    if( paru!=parv )
    {
        if( Size[paru]>Size[parv] )
            par[parv]= paru, Size[paru]+= Size[parv];
        else
            par[paru]= parv, Size[parv]+= Size[paru];
    }
}

void init( int n )
{
    for( int i=0;i<=n;i++ )
        par[i]= i, Size[i]= 1;
}


int main()
{
    int n;
    cin>>n;

    init(n);

    for( int i=1;i<=n;i++ )
    {
        int p;
        cin>>p;

        unite(p,i);
    }

    int ans= 0;
    for( int i=1;i<=n;i++ )
        if( Find(i)==i )
            ans++;

    cout<< ans <<endl;
}
