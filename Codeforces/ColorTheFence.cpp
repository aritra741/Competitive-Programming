#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int v;
    cin>>v;
    ll arr[10];
    arr[0]=0;
    ll mx=0;
    ll ans;
    ll lit;
    ll mn=1000008;
    for(int i=1;i<=9;i++)
        {
            cin>>arr[i];
            mn=min(arr[i], mn);
            ll temp= floor( (double)v/(double)arr[i] );
            if(temp>=mx)
            {
                mx=temp;
                ans=i;
                lit=arr[i];
            }
        }
        if(v<mn)
    {
        cout<<"-1";
        return 0;
    }
        ll rem=v/lit;
    bool flag=0;
    while(v>=lit){
    for(int i=9;i>=1;i--)
    {
        if(arr[i]<=v)
            {
                cout<<i;

            }
        v-=lit;
    }
    }
    ll lim=v/lit;
    for(int i=0;i<lim-1;i++)
        cout<<ans;
    if(flag==0)
        cout<<ans;



}
