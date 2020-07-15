#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    cin>>n;
    int arr[n];
    memset(arr, 0, sizeof(arr));
    for(int i=1;i<n;i++)
        {
            cin>>temp;
            arr[i]=arr[i-1]+temp;
//            cout<<arr[i]<<endl;
        }
    int a,b;
    cin>>a>>b;
    cout<<arr[b-1]-arr[a-1];


}
