#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll k,n,w;
    cin>>k>>n>>w;
    long long tot=k*w*(1+w)/2;
    if(n<tot)
        cout<<tot-n;
    else
        cout<<0;
}
