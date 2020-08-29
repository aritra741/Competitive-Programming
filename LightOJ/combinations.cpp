#include <bits/stdc++.h>
#define ull unsigned long long
#define mod 1000003
using namespace std;

ull mmi(ull n, ull p)
{
    int ans=1;
    if(n>mod)
        n%=mod;
    while(p>0)
    {
        if(p%2!=0)
        {
            ans=(ans*n)%mod;
            p--;
        }
        p/=2;
        n=(n*n)%mod;

    }
    return ans;

}

ull fact[1000001];

int main()
{

    fact[0]=1;
    for(int i=1; i<=1000001; i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }

    int tc;

    ull mi;
    cin>>tc;

    for(int j=1; j<=tc; j++)
    {
        ull n,r;
        scanf("%lld %lld", &n,&r);
        ull ans;
        ull hr=(mmi(fact[r], mod-2)%mod)*(mmi(fact[n-r], mod-2)%mod);
        ans=(hr*fact[n])%mod;
        printf("Case %d: %lld\n", j, ans);
    }
}
