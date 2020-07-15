#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    ll arr[n];
    ll mn=0;
    int cnt=0;
    if(n==2)
        cnt++;
    for(int i=1;i<n;i++)
    {

        cin>>arr[i];
        if(arr[i]<mn)
        {
            cnt++;
            mn=arr[i];
        }
        if(arr[i]<arr[i-1])
            cnt++;
    }
    if(cnt!=2)
        cout<<"NO";
    else
        cout<<"YES";
}

