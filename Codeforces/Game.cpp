#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    if(n & 1)
        cout<<arr[((n+1)/2)-1];
    else
        cout<<arr[(n/2)-1];
}

