#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;

    if(!n)
        return cout<<"a", 0;

    char c= 'a';

    while(n>0)
    {
        ll l= 1, r= n+1;
        ll ans= 0;

        while(r>=l)
        {
            ll x= (r+l)/2;

            if( (x*(x-1))/2>n )
                r= x-1;
            else
                ans= x, l= x+1;
        }

        for( ll i=0;i<ans;i++ )
            cout<<c;
        c++;
        n-= (ans*(ans-1))/2;
    }
}
