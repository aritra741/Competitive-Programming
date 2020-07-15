#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);

    int zer= 0, idx= 0, tot= 0;

    for(int i=0;i<n;i++)
    {
        if(!arr[i])
            zer++;
        else
            tot+=5;
        if(tot and tot%9==0)
            idx= i-zer+1;
    }

    if(!idx and zer)
        cout<<"0\n";
    else if(idx and zer)
    {
        for(int i=0;i<idx;i++)
            cout<<"5";
        for(int i=0;i<zer;i++)
            cout<<"0";
    }
    else
        cout<<"-1\n";
}
