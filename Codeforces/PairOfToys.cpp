#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,k;
    cin>>n>>k;

    if(k==1 or k==2)
        cout<<"0";

    else if(k<=n)
    {
        ll half= k/2;
        if(half+half!=k)
            half++;

        if(k & 1)
            cout<<k-half;
        else
            cout<<k-half-1;
    }

    else
    {
        ll half= k/2;
        if(half<=n)
            cout<<n-half;
        else
            cout<<"0";
    }
}
