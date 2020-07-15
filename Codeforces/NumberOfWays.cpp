#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    ll arr[n+1];
    arr[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
     //   cout<<arr[i]<<endl;
    }
    if(arr[n]%3!=0)
        cout<<0;

    else
    {
        ll third=arr[n]/3;
        ll half=2*third;
        ll cnt=0,t=0;
        for(int i=1; i<n; i++)
        {
           // cout<<arr[i]<<endl;
            if(arr[i]==half)
                t+=cnt;
            if(arr[i]==third)
                cnt++;
            }
        cout<<t;
    }

}
