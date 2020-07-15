#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;

    ll arr[n+5];

    ll ans= 0;

    for( int i=0;i<n;i++ )
        cin>>arr[i], ans= max( ans, arr[i] );

    for( int i=0;i<n;i++ )
        for( int j=0;j<n;j++ )
            ans= max( ans, arr[i]|arr[j] );

    for( int i=0;i<n;i++ )
        for( int j=0;j<n;j++ )
            for( int k=0;k<n;k++ )
                ans= max( ans, arr[i]|(arr[j]|arr[k]) );

    cout<< ans <<endl;
}
