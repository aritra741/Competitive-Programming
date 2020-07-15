#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n+5];

    int ans= 0;

    for( int i=0;i<n;i++ )
        cin>>arr[i], ans= max( ans, arr[i] );

    int l= 1, r= 1e9;

    while(l<r-5)
    {
        int mid= (l+r)/2;

        int j= 1;

        for( int i=0;i<n;i++ )
        {
            if( j%2 and arr[i]<=mid )
                j++;
            else if( j%2==0 )
                j++;
        }

        int jj= j;
        j= 1;

        for( int i=0;i<n;i++ )
        {
            if( j%2==0 and arr[i]<=mid )
                j++;
            else if( j%2 )
                j++;
        }

        if( j>k or jj>k )
            ans= mid, r= mid-1;
        else
            l= mid+1;
    }

    while(l<=r)
    {
        int j= 1;

        for( int i=0;i<n;i++ )
        {
            if( j%2 and arr[i]<=l )
                j++;
            else if( j%2==0 )
                j++;
        }

        int jj= j;
        j= 1;

        for( int i=0;i<n;i++ )
        {
            if( j%2==0 and arr[i]<=l )
                j++;
            else if( j%2 )
                j++;
        }

        if( j>k or jj>k )
            ans= min( ans, l );

        l++;
    }

    cout<<ans<<endl;
}
