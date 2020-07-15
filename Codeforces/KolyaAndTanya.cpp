#include <bits/stdc++.h>
#define ll long long
#define m 1000000007LL
using namespace std;

ll big( ll x, ll p )
{
    x= x%m;
    ll ans=1;

    while(p > 0)
    {
        if(p & 1)
            ans= (ans*x)%m;
        p= p>>1;
        x= (x*x)%m;
    }

    return ans%m;
}

int main()
{
   ll n;
   cin>>n;

   ll tot= big( 3, 3*n );
   ll ex=  big( 7, n);

   cout<< (tot - ex + m) % m <<endl;

}
