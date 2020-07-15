#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> humble;

void pre()
{
    for(ll i=2;i<=500000000;i++)
    {
        ll n= i;
        while(n%2==0)
            n/=2;
        while(n%3==0)
            n/=3;
        while(n%5==0)
            n/=5;
        while(n%7==0)
            n/=7;

        if(n==1)
            humble.push_back(i);
    }

}

int main()
{
    pre();
    cout<<humble.size();
    int n;

    while(cin>>n and n)
        cout<< humble[n-1] <<endl;
}
