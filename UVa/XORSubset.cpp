#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;

ll bigmod( ll x, ll y )
{
    ll res=1;
    while(y>0)
    {
        if(y&1)
            res= (res%m*x%m)%m;
        y>>=1;
        x= (x%m*x%m)%m;
    }

    return res%m;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        ll n;
    }
}
