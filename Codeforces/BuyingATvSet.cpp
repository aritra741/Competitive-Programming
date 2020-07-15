#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll a,b,x,y;
    cin>>a>>b>>x>>y;

    ll newx= x/__gcd( x,y );
    ll newy= y/__gcd( x,y );

    cout<< min( a/newx, b/newy ) <<endl;
}
