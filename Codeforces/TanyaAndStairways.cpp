#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    vector <int> num;
    num.push_back(arr[n-1]);
    int cnt=1;
    for(int i=n-1;i>0;i--)
    {
        if(arr[i]<=arr[i-1])
        {
            cnt++;
            num.push_back(arr[i-1]);
        }
    }

    cout<<cnt<<endl;
    for(int i=cnt-1;i>=0;i--)
        cout<<num[i]<<" ";


}
