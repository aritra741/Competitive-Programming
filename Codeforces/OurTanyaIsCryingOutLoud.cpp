#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,k,a,b;
    cin>>n>>k>>a>>b;

    ll t= n%k;
    ll cnt= 0;

    if(t)
        cnt=t*a, n-=t;

    cnt+=b*((n/k)-1);

    cout<<cnt<<endl;
}
