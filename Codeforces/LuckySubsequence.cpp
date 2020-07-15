#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

map<int,int> mp;
vector<int> v;
ll fact[100007], dp[1050][1050];
bool vis[1050][1050];
int unlucky, sz, k;

ll bigmod( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if( y&1 )
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res;
}

bool isLucky( int n )
{
    while(n>0)
    {
        if( n%10!=4 and n%10!=7 )
            return 0;
        n/= 10;
    }
    return 1;
}

void init()
{
    fact[0]=fact[1]= 1;

    for( int i=2;i<=100000;i++ )
        fact[i]= (fact[i-1]*i)%mod;
}

ll ncr( ll n, ll r )
{
    if(r>n)
        return 0;
    return (((fact[n]*bigmod( fact[r], mod-2 ))%mod)*bigmod( fact[n-r], mod-2 ))%mod;
}

ll rec( int i, int taken )
{
    if( i==sz )
        return ncr( unlucky, k-taken )%mod;

    if( vis[i][taken] )
        return dp[i][taken];

    ll ans= rec( i+1, taken )%mod;

    if( taken+1<=k )
        ans= ( ans+ (v[i]*rec( i+1, taken+1 ))%mod )%mod;

    vis[i][taken]= 1;
    return dp[i][taken]= ans%mod;
}

int main()
{
    init();

    int n;
    scanf("%d %d", &n, &k);

    for( int i=0;i<n;i++ )
    {
        int p;
        scanf("%d", &p);

        if( isLucky(p) )
            mp[p]++;
        else
            unlucky++;
    }

    for( auto x: mp )
        v.push_back( x.second );

    sz= v.size();

    cout<< rec( 0, 0 ) <<endl;
}
