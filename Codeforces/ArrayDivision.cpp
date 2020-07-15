#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[100007];
map<ll, int> mp;

int main()
{
    int n;
    cin>>n;

    ll sum= 0;

    for( int i=0; i<n; i++ )
    {
        scanf("%lld", &arr[i]);
        sum+= arr[i];
    }

    if(sum&1)
    {
        cout<<"NO\n";
        return 0;
    }

    ll tot= 0;
    for( int i=0; i<n; i++ )
    {
        tot+= arr[i];
        mp[arr[i]]++;

        if( tot>=sum/2 )
        {
            ll diff= tot-sum/2;

            if( mp[diff] )
            {
                cout<<"YES\n";
                return 0;
            }
        }
    }

    mp.clear();
    reverse( arr, arr+n );

    tot= 0;
    for( int i=0; i<n; i++ )
    {
        tot+= arr[i];
        mp[arr[i]]++;

        if( tot>=sum/2 )
        {
            ll diff= tot-sum/2;

            if( mp[diff] )
            {
                cout<<"YES\n";
                return 0;
            }
        }
    }

    cout<<"NO\n";
}
