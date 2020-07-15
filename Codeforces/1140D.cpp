#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;

    ll ans= 0;

    int i= 2;
    while(i+1<=n)
        ans+= i*(i+1), i++;

    cout<< ans <<endl;
}
