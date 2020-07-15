#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;

ll ok( ll k )
{
    ll tot= 0;
    ll x= n;

    while(x>=k)
        tot+= k, x-= k, x= x-x/10;
    if(x>0)
        tot+= x;

    return tot;
}

int main()
{
    cin>>n;

    ll l= 1,r= n;

    ll ans= n;

    while(r-l>5)
    {
        ll mid= (l+r)/2;

        if( ok(mid)>=(n+1)/2 )
            ans= mid, r= mid;
        else
            l= mid;
    }

    while(l<=r)
    {
        if( l<ans and ok(l)>=(n+1)/2 )
            ans= l;
        l++;
    }

    cout<< ans <<endl;
}
