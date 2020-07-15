#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;

    while(cin>>n)
    {
        n++;
        n/=2;

        ll ans= (n*n)+(n*n)-3;
        ans*=3;

        cout<< ans <<endl;
    }
}
