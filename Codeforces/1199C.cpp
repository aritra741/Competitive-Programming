#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sum[400007];
ll arr[400007], b[400007];
map<ll,ll>mp;

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    ll n,k;
    cin>>n>>k;

    for( ll i=0; i<n; i++ )
        cin>> arr[i], mp[ arr[i] ]++;

    vector<ll>v;

    for( auto pp: mp )
        v.push_back( pp.first );

    ll tot= 0;
    for( int i=0;i<v.size();i++ )
        sum[i+1]= sum[i]+mp[v[i]], tot+= mp[v[i]];

    ll unique_ase= mp.size();
    ll per_element= (k*8)/n;

    ll x= 1, cc= 0;

    for( ll i=0; i<per_element and x<=unique_ase; i++ )
        x*= 2;

    ll baad= max(0LL,unique_ase-x);
    ll rakhbo= unique_ase-baad;
    ll j= 0;
    ll ans= 1e18;

    for( int i=0; i<v.size(); i++ )
    {
        int j= min( v.size()-1LL, i+rakhbo-1 );

        ll now= sum[j+1]-sum[i];
        now= tot-now;

        ans= min( now, ans );
    }

    cout<< ans <<endl;
}
