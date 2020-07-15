#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll lcm( ll a, ll b )
{
    return (a*b)/__gcd(a,b);
}

int main()
{
    ll n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;

    cout<< (((n/a)-(n/lcm(a,b)))*p)+(((n/b)-(n/lcm(a,b)))*q)+(n/lcm(a,b))*max(p,q) <<endl;
}

