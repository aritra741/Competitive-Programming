#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sum[200007];

int main()
{
    int n,x;
    cin>>n>>x;

    ll arr[2*n+5];

    for( int i=1;i<=n;i++ )
        cin>>arr[i], sum[i]= sum[i-1]+arr[i];

    for( int i=n+1;i<=2*n;i++ )
        arr[i]= arr[n-i], , sum[i]= sum[i-1]+arr[i];

    for( int i=1;i<=n;i++ )
    {
        if(  )
    }
}
