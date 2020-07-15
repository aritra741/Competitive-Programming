#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    int c=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        int org= (arr[i]+c)/m;
        c= (org+1)*m - arr[i];
        if(c<0)
            c=0;
        cout<<org<<" ";



    }
}
