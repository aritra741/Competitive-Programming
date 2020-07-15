#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define plll pair<ll, pll>
#define x first
#define y second
#define gcd first
using namespace std;

plll ExEuclid( ll a, ll b )
{
    if(a==0)
        return plll( b, pll(0,1) );

    plll ex= ExEuclid( b%a, a );

    return plll( ex.gcd, pll(ex.second.y-(b/a)*ex.second.x, ex.second.x ));
}

int main()
{

    ll a,b;

    while(cin>>a>>b)
    {
        plll ans= ExEuclid( a, b );

        if(a==b)
            swap( ans.y.x, ans.y.y );

        cout<<ans.y.x <<" "<<ans.y.y<<" "<<ans.gcd<<endl;
    }

}


