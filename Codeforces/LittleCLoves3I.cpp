#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin>>n;

    if(n%3==0)
        cout<<"1 1 "<<(n-2)<<endl;
    else if(n%3==2)
        cout<<"1 2 "<<n-3<<endl;
    else
        cout<<"1 1 "<<n-3<<endl;
}
