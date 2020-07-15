#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;

    ll arr[n], s[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        s[i]= arr[i];
    }

    sort( s, s+n );

    ll arr1[n+1], s1[n+1];
    arr1[0]= 0, s1[0]= 0;

    for(int i=1;i<=n;i++)
    {
        arr1[i]= arr[i-1]+arr1[i-1];
        s1[i]= s[i-1]+s1[i-1];
    }

    int q;
    cin>>q;

    while(q--)
    {
        int t,l,r;
        cin>>t>>l>>r;

        if(t==1)
            cout<< arr1[r]-arr1[l-1] <<endl;
        else
            cout<< s1[r]-s1[l-1] <<endl;
    }
}
