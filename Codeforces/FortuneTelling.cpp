#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    bool flag=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n, greater<int>());
    for(int i=0;i<n;i++)
    {
        if(arr[i] & 1)
            flag=1;
        ans+=arr[i];
    }
    if(flag==0)
        cout<<0;
    else if(ans & 1)
    cout<<ans;
    else
    {
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i] & 1)
            {
                ans-=arr[i];
                break;
            }
        }
        cout<<ans;
    }
}
