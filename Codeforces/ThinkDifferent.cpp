#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;

int main()
{
    ll n;
    cin>>n;

    if(!n)
    {
        cout<<"1\n";
        return 0;
    }

    ll fir= n;
    for(ll i=1; i<fir; i++)
        n=(n%m*(fir-i)%m)%m;

    fir= n;
    for(ll i=1; i<fir; i++)
        n=(n%m*(fir-i)%m)%m;

    fir= n;
    for(ll i=1; i<fir; i++)
        n=(n%m*(fir-i)%m)%m;

    cout<< n%m <<endl;
}
