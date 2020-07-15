#include <bits/stdc++.h>
using namespace std;

int arr[5000007], arr1[5000007], arr2[5000007];

int main()
{
    int n;

    while(cin>>n and n)
    {
        for(int i=0;i<n;i++)
            cin>>arr1[i]>>arr[i],
            arr2[arr[i]]++;

        bool flag= 1;

        for(int i=0;i<n;i++)
        {
            if( !arr2[arr1[i]] )
            {
                flag= 0;
                break;
            }
            else
                arr2[arr1[i]]--;
        }

        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

        memset(arr,0,sizeof(arr));
        memset(arr,0,sizeof(arr1));
        memset(arr,0,sizeof(arr2));
    }
}
