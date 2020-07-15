#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;

set <int> parents;
int par[1000];
int sz[1000];
pii arr[1000];

void init(int n)
{
    for(int i=0;i<n;i++)
        {
            par[i]=i;
            sz[i]=1;
        }
}

int findP(int r)
{
    if(par[r]==r)
        return r;
    par[r]= findP( par[r] );

    return par[r];
}

void unionN( int p, int q )
{
    int u= findP ( p);
    int v= findP ( q );
    if( u==v )
        return;
    if( sz[u] < sz[v] )
    {
        par[u]=v;
        sz[v]+=sz[u];
    }
    else
    {
        par[v]=u;
        sz[u]+=sz[v];
    }
}

int main()
{
    int n;
    cin>>n;
    init(n);
    for(int i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if( arr[i].first==arr[j].first || arr[i].second==arr[j].second )
                unionN(i, j);
    for(int i=0;i<n;i++)
        parents.insert(  findP(par[i]));
    cout<<parents.size()-1;
}
