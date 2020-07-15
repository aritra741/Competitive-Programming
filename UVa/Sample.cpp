#include <bits/stdc++.h>
#define mod 1000003
using namespace std;
unsigned long long mmi(unsigned long long n, unsigned long long p)
{
    int ans=1;
    if(n>mod)
        n%=mod;
    while(p>0)
    {
        if(p%2!=0)
           {
               ans=(ans*n)%mod;
                p--;}
             p/=2;
            n=(n*n)%mod;

    }
    return ans;

}
unsigned long long fact[1000001];
int main()
{

    fact[0]=1;
    for(int i=1;i<=1000001;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    int tc;
    unsigned long long mi;
    cin>>tc;
    for(int j=1;j<=tc;j++)
    {
    unsigned long long n,r;
    scanf("%lld %lld", &n,&r);
    unsigned long long ans;
    unsigned long long hr=(mmi(r, mod-2)%mod)*(mmi((n-r), mod-2)%mod);
    ans=(hr*fact[n])%mod;
    printf("Case %d: %lld\n", j, ans);
    }
}
