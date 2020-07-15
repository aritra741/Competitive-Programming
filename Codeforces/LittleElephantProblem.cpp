#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr1[100007],arr2[100007];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
        arr2[i]=arr1[i];
    }

    sort(arr1, arr1+n);
    int cnt=0;

    for(int i=0;i<n;i++)
        if(arr1[i]!=arr2[i])
            cnt++;
    if(cnt<=2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
