#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int tot=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        tot+=arr[i];
    }

    sort(arr, arr+n, greater<int>());
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        cnt++;
        if(sum>(tot-sum))
            break;
    }
    cout<<cnt;
}
