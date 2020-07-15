#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;

ll Fac[1000007];
ll Inv[1000007];

ll bigMod( ll b, ll p)
{
    ll res=1;

    while(p>0){
    if(p & 1)
        res= ((res%m)*(b%m))%m;
    p=p>>1;
    b=((b%m)*(b%m)%m);
    }

    return res%m;
}

void preCal(void)
{
    Inv[0]=Fac[0]=1;

    for(ll i=1;i<=1000000;i++)
    {
        Fac[i]=(i*Fac[i-1])%m;
        Inv[i]=bigMod( Fac[i], m-2 );
    }

}

int main()
{
    preCal();

    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int n;
        scanf( "%d", &n );
        ll arr[n];
        ll ans=1,tot=0;
        for(int i=0;i<n;i++)
            {
                scanf("%lld", &arr[i]);
                ll temp= (Fac[tot+arr[i]-1]%m);
                temp=(temp*Inv[arr[i]-1])%m;
                temp=(temp*Inv[ tot ])%m;
                tot+=arr[i];
                ans=(ans*temp)%m;
            }
        printf("Case %d: %lld\n", t, ans);

    }

}

