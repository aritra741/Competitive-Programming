#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr, arr+n);
    for(int i=0;i<n-1;i++)
        cout<<arr[i]<<" ";
    cout<<arr[n-1]<<endl;
}
