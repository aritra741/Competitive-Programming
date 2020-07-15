#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    vector<ll> arr;
    ll a;
    while(cin>>a)
    {
        arr.push_back(a);
        ll sz=arr.size();
        sort(arr.begin(), arr.end());

        if(sz & 1)
        {
            ll mid= (sz+1)/2;
            cout<<arr[mid-1]<<endl;
        }
        else
        {
            ll mid1=sz/2;
            ll mid2=(sz+2)/2;

            cout<<(arr[mid1-1]+arr[mid2-1])/2<<endl;
        }
    }
}
