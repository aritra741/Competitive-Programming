#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,m,q;
    cin>>n>>m>>q;

    ll g= __gcd( n,m );
    ll nr= n/g;
    ll mr= m/g;

    while(q--)
    {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;

        ll lock1, lock2;

        if( a==1 )
            lock1= (b+nr-1)/nr;
        else
            lock1= (b+mr-1)/mr;
        if( c==1 )
            lock2= (d+nr-1)/nr;
        else
            lock2= (d+mr-1)/mr;

        if( lock1!=lock2 )
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}
