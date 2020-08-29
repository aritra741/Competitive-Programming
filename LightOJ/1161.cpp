#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll nc4( ll n )
{
    return (n*(n-1)*(n-2)*(n-3))/24;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        int n;
        scanf("%d", &n);

        map<int,ll>mp, ans;

        for( int i=0;i<n;i++ )
        {
            int p;
            scanf("%d", &p);

            mp[p]++;
        }

        for( int i=10000;i>=1;i-- )
        {
            int cnt= 0;
            ll baad= 0;

            for( int j=1;i*j<=10000;j++ )
                cnt+= mp[i*j], baad+= ans[i*j];

            ans[i]= nc4(cnt)-baad;
        }

        printf("Case %d: %lld\n", t, ans[1]);
    }
}
