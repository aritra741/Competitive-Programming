#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int index=1;
    bool flag=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<=n-1;i++)
    {
        if(i==0 && i!=n-1)
            {
                if(arr[i]%2==0 && arr[i+1]%2==1)
                {
                    flag=1;
                    index=1;
                }
                else if(arr[i]%2==1 && arr[i+1]%2==0)
                {
                    flag=1;
                    index=1;
                }
            }
            else if(i==n-1 && i!=0)
            {
                if(arr[i]%2==0 && arr[i-1]%2==1)
                {
                    index=i+1;
                }
                else if(arr[i]%2==1 && arr[i-1]%2==0)
                {
                    index=i+1;
                }
            }
            else{
        if(arr[i-1]%2==0 && arr[i+1]%2==0 && arr[i]%2==1)
        {
            index=i+1;
            break;
        }
        if(arr[i-1]%2==1 && arr[i+1]%2==1 && arr[i]%2==0)
        {
            index=i+1;
            break;
        }
    }
    }
    cout<<index;
}
