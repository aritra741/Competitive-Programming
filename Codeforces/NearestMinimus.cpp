#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
int main()
{
    ll n,p;
    cin>>n;
    vector <pll> v;
    ll mn=1e18;
    for(int i=0;i<n;i++)
    {
        cin>>p;
        mn=min(mn, p);
        v.push_back(pll(p, i+1) );
    }

    sort(v.begin(), v.end());
    ll ans= 1e18;
    for(int i=0;i<n-1;i++)
    {
        if(v[i].first==v[i+1].first and v[i].first==mn)
        {
            if(abs(v[i].second-v[i+1].second)<ans)
                ans=abs(v[i].second-v[i+1].second);
        }
    }

    cout<<ans<<endl;

}
