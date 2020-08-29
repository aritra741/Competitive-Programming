#include <bits/stdc++.h>
#define ll long long
#define MX 70000
using namespace std;

ll arr[MX];

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        ll n,w;
        scanf("%lld %lld", &n,&w);

        for(ll i=0;i<n;i++)
        {
            ll x,y;
            scanf("%lld %lld", &x,&y);

            arr[i]=y;
        }

        sort(arr, arr+n);

        ll cnt=1;
        ll pos=arr[0]+w;

        for(int i=1;i<n;i++)
        {
            if(arr[i]>pos)
                {
                    pos=arr[i]+w;
                    cnt++;
                }
        }

        printf("Case %d: %lld\n",t,cnt);

    }
}

