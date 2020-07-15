#include<bits/stdc++.h>
#define ll long long
using namespace std;

int arr[200007];

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        map<int,int>mp;
        vector<ll>v;
        int n;
        scanf("%d", &n);

        for( int i=0; i<n; i++ )
            scanf("%d", &arr[i]), mp[ arr[i] ]++;

        ll last= 1e12, ans= 0;

        for( auto x: mp )
            v.push_back( x.second );

        sort( v.begin(), v.end(), greater<int>() );

        for( auto x: v )
        {
            ll now= min( x, last-1 );
            if(!now)
                break;
            last= now;
            ans+= now;
        }

        printf("%lld\n", ans);
    }
}
