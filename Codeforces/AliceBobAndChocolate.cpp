#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    ll bob=0,alice=0,cntb=0,cnta=0;

    for(int i=n-1,j=0;i>=j;)
    {
        if(bob==alice)
            alice+=arr[j],j++,cnta++;
        else if(bob<alice)
            bob+=arr[i],i--,cntb++;
        else
            alice+=arr[j],j++,cnta++;
    }

    cout<<cnta<<" "<<cntb<<endl;
}
