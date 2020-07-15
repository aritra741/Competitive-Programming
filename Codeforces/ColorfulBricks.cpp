#include <bits/stdc++.h>
#define ll long long
#define m 998244353
#define mx 2007
using namespace std;

ll F[mx], I[mx];

ll bigmod( ll x, ll y )
{
    ll ans= 1LL;

    while(y>0)
    {
        if(y&1LL)
            ans=(ans%m*x%m)%m;
        x=(x*x)%m;
        y=y>>1;
    }

    return ans%m;
}

void pre()
{
    F[0]=I[0]= 1LL;

    for(int i=1;i<mx;i++)
    {
        F[i]=(F[i-1]*i)%m;
        I[i]=bigmod(F[i],m-2);
    }
}

int main()
{
    pre();

    ll n,p,k;
    cin>>n>>p>>k;

    ll ans= p;
    ll ncr= (F[n-1]%m*I[k]%m)%m;
    ncr= (ncr%m*I[n-k-1]%m)%m;
    ll forK= bigmod(p-1,k)%m;
    ans= (ans%m*ncr%m)%m;
    ans= (ans%m*forK%m)%m;

    cout<< ans%m <<endl;


}
