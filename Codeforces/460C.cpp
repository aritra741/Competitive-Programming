#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[100007], sum[1000007];
ll n,m,w;

bool ok( ll x )
{
    memset(sum, 0, sizeof(sum));

    ll rem= m;

    for( ll i=1;i<=n;i++ )
    {
        sum[i]+= sum[i-1];

        if( arr[i]+sum[i]>=x )
            continue;

        if( arr[i]+sum[i]+rem<x )
            return 0;

        ll l= i;
        ll r= min( i+w-1, n );
        ll add= x-arr[i]-sum[i];

        if(add>rem)
            return 0;

        sum[l]+= add;
        sum[r+1]-= add;
        rem-= add;
    }

    return 1;
}

int main()
{
    cin>>n>>m>>w;

    for( ll i=1;i<=n;i++ )
        cin>> arr[i];

    ll l= 1, r= 2000000000;
    ll ans= 1;

    while(l<r-5)
    {
        ll mid= (l+r)/2;

        if( ok(mid) )
            ans= mid, l= mid;
        else
            r= mid;
    }

    while(l<=r)
    {
        if( l>ans and ok(l) )
            ans= l;
        l++;
    }

    cout<< ans <<endl;
}
