#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    sort(arr,arr+n);
    int cnt= 0;

    for(int i=1; i<n; i++)
        if(arr[i]<=arr[i-1])
            cnt+=(arr[i-1]-arr[i]+1),
                 arr[i]=arr[i-1]+1;
    cout<< cnt <<endl;
}
