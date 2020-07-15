#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    int mx=0;
    int idxx=-1;
    int mn=100003;
    int idxn=-1;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>mx)
            {
                mx=arr[i];
                idxx=i;
            }
        if(arr[i]<mn)
            {
                mn=arr[i];
                idxn=i;
            }
    }
    int dif=mx-mn;
    int step=ceil( (double)dif/2 );
    if(step>=)
}
