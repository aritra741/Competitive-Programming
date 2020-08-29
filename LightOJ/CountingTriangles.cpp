#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        int n;
        cin>>n;

        int arr[n];

        for( int i=0; i<n; i++ )
            cin>> arr[i];

        sort( arr, arr+n );

        ll ans= 0;

        for( int i=0; i<n; i++ )
            for( int j=i+1; j<n; j++ )
            {
                int pos= upper_bound( arr, arr+n, arr[i]+arr[j]-1 )-arr;
                ans+= pos-j-1;
            }

        cout<<"Case "<<t<<": "<< ans <<endl;
    }
}
