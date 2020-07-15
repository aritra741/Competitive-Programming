#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007ULL
using namespace std;
int main()
{
    ll x,y;
    cin>>x>>y;
    ll n;
    cin>>n;

    int pivot= n%6;

    if(pivot==1)
        cout<<(x+2*mod)%mod<<endl;
    else if(pivot==2)
        cout<<(y+2*mod)%mod<<endl;
    else if(pivot==3)
        cout<<((y-x)+2*mod)%mod<<endl;
    else if(pivot==4)
        cout<<(-x+2*mod)%mod<<endl;
    else if(pivot==5)
        cout<<(-y+2*mod)%mod<<endl;
    else if(pivot==0)
        cout<<(x-y+2*mod)%mod<<endl;
}
