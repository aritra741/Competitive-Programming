#include <bits/stdc++.h>
#define ll long long
using namespace std;

map <ll, ll> mpA;
map <ll, ll> mpS;
map <ll, ll> ::iterator it;

int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll p,q;
        cin>>p>>q;
        mpA[p+q]++;
        mpS[p-q]++;
    }

    ll ans=0;

    for(it=mpA.begin();it!=mpA.end();it++)
    {
        if( it->second>=2 )
        {
            ll t= 1;
            ll i= it->second;
            t*=(i)*(i-1);
            t/=2;
            ans+=t;
        }
    }
    for(it=mpS.begin();it!=mpS.end();it++)
    {
        if( it->second>=2 )
        {
            ll t= 1;
            ll i= it->second;
            t*=(i)*(i-1);
            t/=2;
            ans+=t;
        }
    }

    cout<<ans<<endl;
}
