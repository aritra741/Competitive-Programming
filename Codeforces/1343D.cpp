#include<bits/stdc++.h>
using namespace std;

int sum[400007];

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n,k;
        scanf("%d %d", &n, &k);

        map<int,int>mp;

        int arr[n+5];

        for( int i=0; i<n; i++ )
            scanf("%d", &arr[i]);

        for( int i=0; i<n/2; i++ )
            mp[ arr[i]+arr[n-i-1] ]++,
            sum[ min( arr[i], arr[n-i-1] )+1 ]++,
            sum[ k-min( arr[i], arr[n-i-1] )+arr[i]+arr[n-i-1]+1 ]--;

        for( int i=1; i<=2*k; i++ )
            sum[i]+= sum[i-1];

        int ans= 2*n;

        for( int x=2; x<=2*k; x++ )
            ans= min( ans, sum[x]-mp[x]+(n/2-(sum[x]-mp[x])-mp[x])*2 );

        printf("%d\n", ans);

        for( int i=0; i<=2*k+5; i++ )
            sum[i]= 0;
    }
}
