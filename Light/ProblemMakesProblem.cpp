#include <bits/stdc++.h>
#define ll long long
#define mx 2000007
#define m 1000000007
using namespace std;

ll F[mx];

ll bigmod( ll x, ll y )
{
    ll ans= 1;

    while(y>0)
    {
        if(y&1)
            ans=(ans%m*x%m)%m;
        y=y>>1;
        x=(x*x)%m;
    }

    return ans%m;
}

void pre()
{
    F[0]=1;

    for(int i=1; i<mx; i++)
        F[i]= (F[i-1]*i)%m;
}

int main()
{
    pre();

    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        ll n,k;
        scanf("%lld %lld", &n,&k);

        ll ans= F[n+k-1]%m;
        ll Iofn= bigmod( F[n], m-2 )%m;
        ans= (ans*Iofn)%m;
        ll Iofk= bigmod( F[k-1], m-2 )%m;
        ans= (ans*Iofk)%m;

        printf("Case %d: %lld\n", t, ans);
    }

}

