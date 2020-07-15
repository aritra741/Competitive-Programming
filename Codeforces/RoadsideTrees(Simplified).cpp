#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    ll sum=arr[0]+1;
    for(int i=1;i<n;i++)
    {
        int diff=abs(arr[i-1]-arr[i]);
            sum+=diff+2;
    }

    cout<<sum<<endl;
}
