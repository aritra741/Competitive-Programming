#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime( ll x )
{
    ll sq= sqrt(x);

    for(ll i=2; i<=sq; i++)
        if(x%i==0)
            return 0;
    return 1;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        ll a,b;
        cin>>a>>b;

        if(a-b==1 and isPrime(a+b))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
