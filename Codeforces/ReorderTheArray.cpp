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
    int cnt=0;
    for(int i=0,j=0;i<n and j<n;)
    {
        if(arr[i]<arr[j])
        {
            i++,j++,cnt++;
        }
        else
            j++;

    }

    cout<<cnt;
}
