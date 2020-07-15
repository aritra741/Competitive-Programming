#include<bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,ll>mp;

int main()
{
    int n;
    cin>>n;

    ll p;

    for( int i=1;i<=n;i++ )
        cin>>p, mp[i-p]+= p;

    ll ans= 0;

    for( auto x: mp )
        ans= max( ans, x.second );

    cout<< ans <<endl;
}
