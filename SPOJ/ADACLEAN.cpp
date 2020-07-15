#include <bits/stdc++.h>
#define ll long long
#define p1 31
#define p2 37
#define mod1 1000000021
#define mod2 1000003469
#define mx 1000007
#define pii pair<ll,ll>
using namespace std;

map<pii,ll> mp;
vector<int>adj[mx];
ll Pow1[mx], Pow2[mx];
ll inv1, inv2;
pii Hash[mx];

ll bigmod( ll x, ll y, ll m )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x)%m;
        x= (x*x)%m;
        y>>= 1;
    }

    return res;
}

void init()
{
    Pow1[0]= Pow2[0]= 1;

    for( int i=1; i<mx; i++ )
        Pow1[i]= (Pow1[i-1]*p1)%mod1,
        Pow2[i]= (Pow2[i-1]*p2)%mod2;

    inv1= bigmod( p1, mod1-2, mod1 );
    inv2= bigmod( p2, mod2-2, mod2 );
}

int main()
{
    init();

    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n,k;
        scanf("%d %d", &n, &k);
        char s[n+5];
        scanf("%s", s);

        ll h= 0, h2= 0;

        for( int i=0; i<k; i++ )
            h= ( h+ ( s[i]*Pow1[i+1] )%mod1 )%mod1,
            h2= ( h2+ ( s[i]*Pow2[i+1] )%mod2 )%mod2;

        mp[ pii(h,h2) ]++;

        int last= 0;
        for( int i=k; i<n; i++ )
        {
            h= ( h- s[last]*p1+mod1 )%mod1;
            h= ( h*inv1 )%mod1;
            h= ( h+ s[i]*Pow1[k] )%mod1;
            h2= ( h2- s[last]*p2+mod2 )%mod2;
            h2= (h2*inv2)%mod2;
            h2= ( h2+ s[i]*Pow2[k] )%mod2;
            last++;

            mp[ pii(h,h2) ]++;
        }

        printf("%d\n", (int)mp.size());
        mp.clear();
    }
}
