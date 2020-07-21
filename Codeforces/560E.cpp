#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second
#define mod 1000000007
#define mx 200007
using namespace std;

ll f[mx], inv[mx];
pii box[mx];
ll dp[mx];
int t;

bool count_kora_jaabe( pii a, pii b )
{
    if( a.ff<=b.ff and a.ss<=b.ss )
        return 1;
    return 0;
}

ll Pow( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res;
}

bool cmp( pii a, pii b )
{
    if( a.ff==b.ff )
        return a.ss<b.ss;
    return a.ff<b.ff;
}

void init()
{
    f[0]= f[1]= inv[0]= inv[1]= 1;

    for( ll i=2;i<mx;i++ )
        f[i]= ( f[i-1]*i )%mod,
        inv[i]= Pow( f[i], mod-2 );
}

ll number_of_ways( pii x, pii y )
{
    ll tot= f[abs(x.ff+x.ss-y.ff-y.ss)];
    ll nich= inv[y.ff-x.ff];
    nich= ( nich*inv[y.ss-x.ss] )%mod;

    return (tot*nich)%mod;
}

ll ways( pii p, int id )
{
    ll tot= number_of_ways( pii(1,1), p );

    for( int i=0;i<id;i++ )
        if( count_kora_jaabe( box[i], p ) )
            tot= (tot-(dp[i]*number_of_ways( box[i], box[id] ))%mod+mod)%mod;

    return tot;
}

int main()
{
    init();

    int n,m;
    cin>>n>>m>>t;

    for( int i=0;i<t;i++ )
        cin>>box[i].ff>>box[i].ss;

    box[t]= pii(n,m);

    sort( box, box+t+1, cmp );

    for( int i=0;i<=t;i++ )
        dp[i]= ways( box[i], i );

    cout<< dp[t] <<endl;
}

