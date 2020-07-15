#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define f first
#define s second
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;

    map<ll, ll> mp;
    ll arr[n];
    pll time[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }

    for(int i=0; i<n; i++)
    {
        cin>>time[i].f;
        time[i].s= arr[i];
    }

    sort( time, time+n );
    int tot= mp.size();

    int rem= k-tot;

    ll ans= 0;

    for(int i=0;i<n;i++)
    {
        if(!rem)
            break;
        if( mp[ time[i].s ]<2 )
            continue;
        rem--;
        ans+=time[i].f;
        mp[ time[i].s ]--;
    }

    cout<<ans<<endl;




}
