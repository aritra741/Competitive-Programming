#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,l,r,x;
int arr[16];

int main()
{
    cin>>n>>l>>r>>x;

    for( int i=0;i<n;i++ )
        cin>>arr[i];

    ll ans= 0;
    for( int i=1;i<=(1<<n);i++ )
    {
        ll sum= 0;
        int mn= 2e9, mx= -1;
        for( int j=0;j<n;j++ )
            if( (1<<j)&i )
                mn= min( mn, arr[j] ),
                mx= max( mx, arr[j] ),
                sum+= arr[j];

        if(sum>=l and sum<=r and mx-mn>=x)
            ans++;
    }

    cout<< ans <<endl;
}
