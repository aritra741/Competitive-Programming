#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

map <pll, string> mp;

int main()
{
    ll n;
    cin>>n;
    while(n--)
    {
        ll p,q;
        string s;
        cin>>p>>q>>s;
        mp[ pll(p,q) ]=s;
    }

    ll t;
    cin>>t;

    while(t--)
    {
        ll p,q;
        cin>>p>>q;
        cout<<mp[pll(p,q)]<<endl;
    }
}
