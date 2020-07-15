#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;

    ll mx= -1;

    while(n--)
    {
        ll p,q;
        cin>>p>>q;

        mx= max( mx, p+q );
    }

    cout<<mx<<endl;
}
