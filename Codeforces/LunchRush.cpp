#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll mx=-1000000000;
    for(int i=0;i<n;i++)
    {
        ll t,f;
        cin>>f>>t;
        ll temp=(t>k)? f-(t-k) : f;
        mx=max(temp, mx);
    }

    cout<<mx;

}
