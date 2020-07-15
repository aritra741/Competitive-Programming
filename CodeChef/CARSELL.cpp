#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int arr[100007];

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        for( int i=0;i<n;i++ )
            scanf("%d", &arr[i]);

        sort( arr, arr+n, greater<int>() );

        ll ans= 0;

        for( int i=0;i<n;i++ )
            if( arr[i]-i>0 )
                ans= ( ans+arr[i]-i )%mod;

        printf("%lld\n", ans);
    }
}
