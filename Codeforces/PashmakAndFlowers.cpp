#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<int,int> mp;

int main()
{
    ll n;
    cin>>n;

    ll arr[n];
    ll mx= 0, mn= 2000000000;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[ arr[i] ]++;
        mx= max(mx, arr[i]);
        mn= min(mn, arr[i]);
    }

    int diff= mx-mn;
    cout<< diff <<" ";

    ll tot= 0;

    if(diff==0)
    {
        cout<< (n*(n-1))/2 <<endl;
        return 0;
    }

    for(int i=0;i<n;i++)
    {
        tot+= mp[ arr[i]+diff ];
        tot+= mp[ arr[i]-diff ];
        mp[ arr[i] ]--;
    }

    cout<< tot <<endl;
}
