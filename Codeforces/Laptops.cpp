#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    if(n<2)
    {
        cout<<"Poor Alex";
        return 0;
    }
    pair <ll, ll> arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr, arr+n);
    for(ll i=1;i<n;i++)
    {
        if(arr[i].second<arr[i-1].second)
        {
            cout<<"Happy Alex"<<endl;
            return 0;
        }

    }
    cout<<"Poor Alex"<<endl;
}
