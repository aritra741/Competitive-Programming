#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

ll bigmod( ll x, ll y )
{
    ll res= 1;

    while( y>0 )
    {
        if(y&1)
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res;
}

int main()
{
    int tc;
    cin>>tc;

    for( int t=1;t<=tc;t++ )
    {
        ll p;
        cin>>p;

        cout<<"Case #"<<t<<": "<< ( p*bigmod( 2, p-1 ) )%mod <<endl;
    }
}
