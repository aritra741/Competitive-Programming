#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll arr[3];
    ll tot=0;
    for(int i=0;i<3;i++)
        {
            cin>>arr[i];
            tot+=arr[i];
        }
    sort(arr, arr+3);
    cout<<min(tot/3, arr[0]+arr[1]);
    }

