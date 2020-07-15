#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector <int> arr(n);
    vector <int> ::iterator it;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    if(is_sorted(arr.begin(), arr.end()))
    {
        cout<<"0"<<endl;
        return 0;
    }
    it= is_sorted_until(arr.begin(), arr.end());
    int pos= it-arr.begin();
    bool flag=0;
    for(int i=pos;i<n-1;i++)
        if(arr[i]>arr[i+1])
            flag=1;
    if(flag)
        cout<<"-1"<<endl;
    else if(!flag and arr[n-1]<=arr[0])
        cout<<n-pos<<endl;
    else
        cout<<"-1"<<endl;

}
