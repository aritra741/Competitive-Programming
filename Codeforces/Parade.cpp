#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;

    ll arr[n][2];
    int mx= 0, l= 0,r= 0, idx= 0;
    ll totl= 0, totr= 0;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        totl+= arr[i][0],
        totr+= arr[i][1];
    }

    mx= llabs(totl-totr);

    for(int i=0;i<n;i++)
    {
        ll nowl= totl-arr[i][0]+arr[i][1];
        ll nowr= totr+arr[i][0]-arr[i][1];

        ll diff= llabs(nowl-nowr);

        if(diff>mx)
            idx= i+1,
            mx= diff;
    }

    cout<< idx <<endl;
}
