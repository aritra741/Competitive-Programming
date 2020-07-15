#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,t;
    cin>>n>>t;

    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int len= 0, mx= 0;
    int fir= 0;
    ll now= 0;

    for(int i=0;i<n;i++)
    {
        now+=arr[i];

        if(now>t)
            now-=arr[fir], fir++, mx= max(mx, len) ;
        else
            len++;
    }

    mx= max(mx, len);

    cout<< mx <<endl;
}
