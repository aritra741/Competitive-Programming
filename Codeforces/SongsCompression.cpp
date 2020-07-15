#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        sum+=a;
        arr[i]=a-b;
    }

    sort(arr, arr+n, greater<int>());

    int cnt=0,i=0;
    bool flag=0;
    while(sum>m and i<n)
    {
        flag=1;
        sum-=arr[i];
        i++,cnt++;
    }

    if(sum>m)
        cout<<"-1"<<endl;
    else
        cout<<cnt<<endl;
}
