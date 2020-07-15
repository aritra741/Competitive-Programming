#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    bool flag=0;
    int cnt=0;
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr, arr+n);
    for(int i=0;i<n-2;i++)
    {
        if(arr[i]+arr[i+1]>arr[i+2] && arr[i+2]+arr[i]>arr[i+1] && arr[i+2]+arr[i+1]>arr[i])
            {
                flag=1;
                break;
            }

        }

    if(flag==0)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

}
