#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll lcm( ll a, ll b )
{
    return (a*b)/__gcd(a,b);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        ll n,a,b,k;
        cin>>n>>a>>b>>k;

        ll cnt1= n/a-n/lcm(a,b);
        ll cnt2= n/b-n/lcm(a,b);

        if(cnt1+cnt2>=k)
            cout<<"Win\n";
        else
            cout<<"Lose\n";
    }
}
