#include <bits/stdc++.h>
#definr ll long long
#define pll pair<ll,ll>
using namespace std;

pll extended_euclid(ll a, ll b)  // returns x, y | ax + by = gcd(a,b)
{
    if(b == 0)
        return pll(1, 0);
    else
    {
        pll d = extended_euclid(b, a%b);
        return pll(d.second, d.first - d.second*(a/b));
    }
}

int main()
{
    int a,b;
    cin>>a>>b;

    cout<< extended_euclid(a,b).first <<" "<< extended_euclid(a,b).second <<endl;
}
