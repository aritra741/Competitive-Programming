#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[200007];

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n/2; i++)
        cin>>arr[i];

    ll diff= 0, mn= 0;

    for(int i=0; i<n/2; i++)
    {
        if(i and arr[i]-arr[i-1]>0)
        {
            diff= arr[i]-arr[i-1];
            mn= max(mn, diff);
            arr[i]-=mn;
            cout<<mn<<" ";
        }

        else
            {
                cout<<mn<<" ";
                arr[i]-=mn;
            }
    }

    for(int i=(n/2)-1; i>=0; i--)
        cout<<arr[i]<<" ";
}

