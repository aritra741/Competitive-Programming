#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
int main()
{
    ll n,temp;
    cin>>n;
    pll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr, arr+n);
    ll mn=arr[0].second;
    for(int i=1; i<n; i++)
    {
        if(arr[i].second>=mn)
            mn=arr[i].second;
        else
            mn=arr[i].first;
    }
    cout<<mn<<endl;
}
