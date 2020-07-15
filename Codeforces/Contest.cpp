#include <bits/stdc++.h>
#define  ll long long
using namespace std;
int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll M=max(3*a/10, a-(a*c/250));
    ll V=max(3*b/10, b-(b*d/250));
    if(M>V)
        cout<<"Misha";
    else if(V>M)
        cout<<"Vasya";
    else
        cout<<"Tie";

}
