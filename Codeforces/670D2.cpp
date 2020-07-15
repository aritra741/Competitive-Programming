#include<bits/stdc++.h>
#define mx 100007
#define ll long long
using namespace std;

ll n,k;
ll a[mx], b[mx];

bool ok( ll x )
{
    ll rem= 0;

    for( int i=0;i<n;i++ )
    {
        ll lagbe= a[i]*x;
        ll tot= lagbe-b[i];

        if(tot>k)
            return 0;

        rem+= max( 0LL, tot );

        if(rem>k)
            return 0;
    }

    if(rem<=k)
        return 1;
    return 0;
}

int main()
{
    cin>>n>>k;

    for( int i=0;i<n;i++ )
        cin>> a[i];
    for( int i=0;i<n;i++ )
        cin>> b[i];

    ll l= 0, r= 2000000000;
    ll ans= 0;

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
