#include<bits/stdc++.h>
#define ll long long
#define ll long long
using namespace std;

ll mod[1007], arr[200007];

int main()
{
    int n, m;
    cin>>n>>m;

    int ans= 1%m;

    for( int i=0; i<n; i++ )
        cin>> arr[i];

    if( n<=m )
        for( int i=0;i<n;i++ )
            for( int j=i+1;j<n;j++ )
                ans= ( ans*(abs(arr[i]-arr[j]))%m )%m;

    else
        ans= 0;

    cout<<ans<<endl;
}

