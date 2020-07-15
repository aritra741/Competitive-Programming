#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll votes[3010];
vector <pll> arr;

int main()
{
    ll n,m,mx=-1, partymx=-1;
    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        ll v,c;
        cin>>v>>c;
        votes[v]++;
        if(votes[v]>mx)
        {
            mx=votes[v];
            partymx=v;
        }
        arr.push_back( pll(c, v) );
    }

    sort( arr, arr+n );
    ll sum=0;

    if(votes[1]<=mx and and partymx!=1)
    for(int i=0;i<n;i++)
    {
        if( arr[i].second!=1 )
        {

        }
    }
}
