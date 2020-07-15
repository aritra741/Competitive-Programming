#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main()
{
    ll a,b,c,x,y;
    cin>>a>>b>>c;

    ll g= gcd( min( a,b ), max(a,b), x, y );

    if( c%g )
        cout<<"No\n";
    else
    {
        double p1= ( -1.0*g*x )/b;
        double p2= ( 1.0*g*y )/a;
        cout<<p1<<" "<<p2<<endl;
        if( p1<=p2 )
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
