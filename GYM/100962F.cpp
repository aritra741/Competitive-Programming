#include<bits/stdc++.h>
#define ll long long
#define sf(x) scanf("%d", &x)
#define mx 200007
#define mx1 200007
#define pii pair<int,int>
#define ff first
#define ss second
#define INF 100010
using namespace std;

int arr[mx], base[mx];
vector<int>adj[mx], cost[mx];
int par[mx][20];
int cnt[mx], cntnode[mx];
int st[mx], en[mx], lvl[mx];
ll sum, ans[mx1];
bool active[mx];
pii ekhon[mx];
int mp[mx];
int T;
bitset<INF> nai;

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


void dfs( int u, int p )
{
    st[u]= ++T;
    base[T]= u;
    par[u][0]= p;

    for( int i=0; i<adj[u].size(); i++ )
    {
        int v= adj[u][i];
        int w= cost[u][i];

        if(p==v)
            continue;

        arr[v]= w;
        lvl[v]= lvl[u]+1;
        dfs( v, u );
    }

    en[u]= ++T;
    base[T]= u;
}

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

} qq[mx1];

bool cmp(query &a, query &b)
{
    return a.ord<b.ord;
}

inline void toggle( int id )
{
    if( arr[ base[ id ] ]<mx and active[ base[ id ] ] )
    {
        cnt[ arr[ base[ id ] ] ]--;

        if( !cnt[ arr[ base[ id ] ] ] )
            nai[ arr[ base[ id ] ] ]= 1;
    }
    else if( arr[ base[ id ] ]<mx )
    {
        cnt[ arr[ base[ id ] ] ]++;

        if( cnt[ arr[ base[ id ] ] ]==1 )
            nai[ arr[ base[ id ] ] ]= 0;
    }

    active[ base[ id ] ]^= 1;
}

int main()
{
    nai.set();

    int n,q;
    scanf("%d %d", &n, &q);

    for( int i=1; i<n; i++ )
    {
        int a,b,w;
        sf(a);
        sf(b);
        sf(w);

        adj[a].push_back(b);
        adj[b].push_back(a);
        cost[a].push_back(w);
        cost[b].push_back(w);
    }

    dfs(1,1);
    arr[1]= n+5;

    for( int j=1; j<20; j++ )
        for( int i=1; i<=n; i++ )
            par[i][j]= par[par[i][j-1]][j-1];

    int a,b;

    for( int i=1; i<=q; i++ )
    {
        sf(a);
        sf(b);
        int L= lca(a,b);

        if( st[a]>st[b] )
            swap(a,b);

        if( a==L )
        {
            qq[i].l= st[ a ]+1;
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

    sort( qq+1, qq+q+1, cmp );

    int l= qq[1].l, r= qq[1].l-1;

    for( int i=1; i<=q; i++ )
    {
        while(l<qq[i].l)
            toggle(l++);
        while(r<qq[i].r)
            toggle(++r);
        while(l>qq[i].l)
            toggle(--l);
        while(r>qq[i].r)
            toggle(r--);

        ans[ qq[i].id ]= nai._Find_first();
    }

    for( int i=1; i<=q; i++ )
        printf("%lld\n",  ans[i] );
}

