#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
int main()
{
    ull n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    sort(arr, arr+n);
    int pos;
    if(arr[0]<=0)
        pos=1;
    else
        pos=arr[0];
    ull sum=0;
    for(ll i=0;i<n;i++)
    {
        sum+=abs(arr[i]-pos);
        pos++;
    }
    cout<<sum;
}
