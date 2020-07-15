#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

ll arr[200020];
map <ll,ll> mp;

bool comp(const pll &a, const pll &b)
{
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}

int main()
{
    ll n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    pll cmp[n];

    for(int i=0;i<n;i++)
    {
        cin>>cmp[i].first;
        cmp[i].second=i;
    }

    sort(cmp, cmp+n, comp);
    sort(arr, arr+n, greater<ll>());

    for(int i=0;i<n;i++)
        mp[ cmp[i].second ] = i;

    for(int i=0;i<n;i++)
        cout<<arr[ mp[i] ]<<" ";

}

