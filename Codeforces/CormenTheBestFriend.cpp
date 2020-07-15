#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int cnt= 0;

    for(int i=1;i<n;i++)
    {
        int ex= k-arr[i-1];

        if(ex>arr[i])
            cnt+=ex-arr[i], arr[i]=ex;
    }

    cout<<cnt<<endl;

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
