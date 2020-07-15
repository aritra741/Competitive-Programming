#include<bits/stdc++.h>
#define ll long long
using namespace std;

priority_queue<ll>hh,ww;

int main()
{
    ll w,h,n;
    cin>>w>>h>>n;

    while(n--)
    {
        char c;
        ll x;
        cin>>c>>x;

        if(c=='H')
            hh.push(x),
            hh.push(h-x);
        else
            ww.push(x),
            ww.push(w-x);

        cout<< hh.top()*ww.top() <<'\n';
    }
}
