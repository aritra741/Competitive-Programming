#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Update(ll bit[], ll n, ll idx, ll val)
{

    while(idx<=n)
    {
        bit[idx]+=val;
        idx=idx + (idx&(-idx));
    }
}

ll getsum(ll bit[], ll idx, ll n)
{

    ll sum=0;
    while(idx>0)
    {
        sum+=bit[idx];
        idx=idx- (idx&(-idx));
    }
    return sum;
}


int main()
{
    int tc;
    cin>>tc;
    for(int i=1; i<=tc; i++)
    {
        printf("Case %d:\n", i);
        ll n,q;
        scanf("%lld %lld", &n,&q);
        ll arr[n+1];
        memset(arr, 0, sizeof(arr));
        ll org[n];
        for(ll j=1; j<=n; j++)
        {

            scanf("%lld", &org[j-1]);
            Update(arr, n, j, org[j-1]);
        }

        for(int k=1; k<=q; k++)
        {
            ll qt, q1,q2,q3;
            scanf("%lld", &qt);

            if(qt==1)
            {
                scanf("%lld", &q1);
                ll ans=getsum(arr, q1+1,n)-getsum(arr, q1, n);
                printf("%lld\n", ans);
                Update(arr, n, q1+1, -ans);
                org[q1]=0;


            }
            else
            {
                scanf("%lld %lld", &q2, &q3);
                if(qt==2)
                {
                    Update(arr, n, q2+1, q3);
                    org[q2]+=q3;
                }
                else
                {
                    ll ans=getsum(arr, q3+1,n)-getsum(arr, q2, n);
                    printf("%lld\n", ans);
                }
            }
        }
    }
}

