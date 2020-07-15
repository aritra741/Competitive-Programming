#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string arr1[n],arr2[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }

    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    int cnt=0;

    for(int i=n-1;i>=0;i--)
    {
        cout<<arr1[i]<<" "<<arr2[i]<<endl;

        int len1=arr1[i].length();
        int len2=arr2[i].length();

        if(arr2[i]!=arr1[i] and len1==len2)
        {
                    cnt++;

        }
    }

    cout<<cnt<<endl;

}
