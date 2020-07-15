#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mx 2000007
using namespace std;

bool active[mx];
int st[mx], en[mx];
int base[mx], lvl[mx];
ll cnt[mx], power[mx][8];
ll val[mx];
ll inv[mx];
bool ok[mx];
int par[mx][20];
vector<int> factors[mx], adj[mx];

int T;
ll ans= 1;

ll out[mx];

inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
{
    if (pow == 0)
    {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
                  (y < hpow) ? 0 : 3
              ) : (
                  (y < hpow) ? 1 : 2
              );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct query
{
    int l,r,id;
    ll ord;

    void calcord()
    {
        ord= gilbertOrder(l,r,21,0);
    }

} qq[mx];

bool cmp(query &a, query &b)
{
    return a.ord<b.ord;
}

void dfs( int u, int p )
{
    st[u]= ++T;
    base[T]= u;
    par[u][0]= p;

    for( auto v: adj[u] )
    {
        if(p==v)
            continue;
        lvl[v]= lvl[u]+1;
        dfs( v, u );
    }

    en[u]= ++T;
    base[T]= u;
}

void init()
{
    inv[1] = 1;
    for ( int i = 2; i <mx; i++ )
    {
        inv[i] = (-(mod/i) * inv[mod%i] ) % mod;
        inv[i] = inv[i] + mod;
    }
}

void sieve()
{
    ok[0]= ok[1]= 1;

    for( ll i=2; i<mx; i++ )
    {
        if( !ok[i] )
        {
            factors[i].push_back(i);
            for( ll j=i*2; j<mx; j+=i )
                ok[j]= 1, factors[j].push_back(i);
        }
    }
}

inline void add( int p )
{
    cout<<p<<" "<<ans<<" ";


    for( int i=0; i<factors[p].size(); i++ )
    {
        int x= factors[p][i];
        cnt[x]+= power[p][i];

        ans= ( ans*( cnt[x]+1 ) )%mod;
    }

}

inline void Remove( int p )
{
    for( auto x: factors[p] )
        if( cnt[x] )
            ans= ( ans*inv[ cnt[x]+1 ] )%mod;

    for( int i=0; i<factors[p].size(); i++ )
    {
        int x= factors[p][i];
        cnt[x]-= power[p][i];

        ans= ( ans*( cnt[x]+1 ) )%mod;
    }
}

inline void toggle( int idx )
{
    int p= val[ base[idx] ];

//    cout<<idx<<" "<<base[idx]<<" "<<p<<endl;

    for( auto x: factors[p] )
        if( cnt[x] )
            ans= ( ans*inv[ cnt[x]+1 ] )%mod;

    if( active[ base[idx] ] )
    {
        for( int i=0; i<factors[p].size(); i++ )
        {
            int x= factors[p][i];
            cnt[x]-= power[p][i];

            ans= ( ans*( cnt[x]+1 ) )%mod;
        }
    }
    else
    {
        for( int i=0; i<factors[p].size(); i++ )
        {
            int x= factors[p][i];
            cnt[x]+= power[p][i];

            ans= ( ans*( cnt[x]+1 ) )%mod;
        }
    }

    active[ base[idx] ]^= 1;
}

int lca(int u,int v)
{
    if(lvl[u]<lvl[v])
        swap(u,v);
    for(int k=19; k>=0; k--)
        if(lvl[par[u][k]]>=lvl[v])
            u=par[u][k];
    if(u==v)
        return u;
    for(int k=19; k>=0; k--)
        if(par[u][k]!=par[v][k])
            u=par[u][k],v=par[v][k];
    return par[u][0];
}

int main()
{
    sieve();
    init();

    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        for( int i=1; i<n; i++ )
        {
            int p,q;
            scanf("%d %d", &p, &q);

            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        dfs( 1,1 );

        for( int j=1; j<20; j++ )
            for( int i=1; i<=n; i++ )
                par[i][j]= par[par[i][j-1]][j-1];

        for( int i=1; i<=n; i++ )
        {
            scanf("%lld", &val[i]);

            ll x= val[i];

            if( power[x][0] )
                continue;

            for( int j=0; j<factors[x].size(); j++ )
            {
                int kk= factors[x][j];
                int cc= 0;
                ll xx= x;

                while( xx%kk==0 )
                    cc++, xx/= kk;

                power[x][j]= cc;
            }
        }

        int q;
        scanf("%d", &q);

        for( int i=0; i<q; i++ )
        {
            int a,b;
            scanf("%d %d", &a, &b);

            int L= lca(a,b);
//            cout<<"LCA holo "<<lca(a,b)<<endl;

            if( st[a]>st[b] )
                swap(a,b);

            if( a==L )
            {
                qq[i].l= st[ a ];
                qq[i].r= st[ b ];
            }
            else
            {
                qq[i].l= en[ a ];
                qq[i].r= st[ b ];
            }

            qq[i].id= i;
            qq[i].calcord();
        }

        sort( qq, qq+q, cmp );

        int l= qq[0].l, r= qq[0].l-1;

        for( int i=0; i<q; i++ )
        {
            while(r<qq[i].r)
                toggle(++r);
            while(l>qq[i].l)
                toggle(--l);
            while(l<qq[i].l)
                toggle(l++);
            while(r>qq[i].r)
                toggle(r--);

            int L= lca( base[qq[i].l], base[qq[i].r] );

            if( base[qq[i].l]!=L and base[qq[i].r]!=L )
                toggle( st[L] );

            out[ qq[i].id ]= ans;

            if( base[qq[i].l]!=L and base[qq[i].r]!=L )
                toggle( st[L] );
        }

        for( int i=0; i<q; i++ )
            printf("%lld\n", out[i]);

        for( int i=1;i<=n;i++ )
            adj[i].clear();
        T= 0;
        memset( cnt, 0, sizeof(cnt) );
        memset( active, 0, sizeof(active) );
        ans= 1;
        lvl[1]= 0;
    }
}
