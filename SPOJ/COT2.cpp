#include<bits/stdc++.h>
#define ll long long
#define sf(x) scanf("%d", &x)
#define mx 80007
#define mx1 100007
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int arr[mx], base[mx];
vector<int>adj[mx];
int par[mx][20];
int cnt[mx], cntnode[mx];
int st[mx], en[mx], lvl[mx];
ll sum, ans[mx1];
bool active[mx];
pii ekhon[mx];
int mp[mx];
int T;

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
//    cout<<"toggle "<<id<<" ";

    if( active[ base[ id ] ] )
    {
        cnt[ arr[ base[ id ] ] ]--;

        if( !cnt[ arr[ base[ id ] ] ] )
            sum--;
    }
    else
    {
        cnt[ arr[ base[ id ] ] ]++;

        if( cnt[ arr[ base[ id ] ] ]==1 )
            sum++;
    }

    active[ base[ id ] ]^= 1;

//    cout<<sum<<endl;
}

int main()
{
    int n,q;
    scanf("%d %d", &n, &q);

    for( int i=1; i<=n; i++ )
        sf(ekhon[i].ff), ekhon[i].ss= i;

    sort( ekhon+1, ekhon+n+1 );

    int cc= 1;

    for( int i=1; i<=n; i++ )
    {
        if( ekhon[i].ff!=ekhon[i-1].ff )
            arr[ ekhon[i].ss ]= cc++;
        else
            arr[ ekhon[i].ss ]= arr[ ekhon[i-1].ss ];
//        cout<<"eikhane "<<ekhon[i].ff<<" "<<arr[ekhon[i].ss]<<endl;
    }

//        for( int i=1;i<=n;i++ )
//            cout<<i<<" "<<arr[i]<<endl;

    for( int i=1; i<n; i++ )
    {
        int p,q;
        sf(p);
        sf(q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    dfs(1,1);

//    for( int i=1;i<=2*n;i++ )
//        cout<<arr[base[i]]<<" ";
//    cout<<endl;

//    for( int i=1;i<=2*n;i++ )
//        cout<<base[i]<<" ";
//    cout<<endl;
    for( int j=1; j<20; j++ )
        for( int i=1; i<=n; i++ )
            par[i][j]= par[par[i][j-1]][j-1];

    int a,b;

    for( int i=1; i<=q; i++ )
    {
        sf(a);
        sf(b);
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

    sort( qq+1, qq+q+1, cmp );

    int l= qq[0].l, r= qq[0].l-1;

    for( int i=1; i<=q; i++ )
    {
//        cout<<qq[i].l<<" "<<qq[i].r<<":\n";

        while(l<qq[i].l)
            toggle(l++);
        while(r<qq[i].r)
            toggle(++r);
        while(l>qq[i].l)
            toggle(--l);
        while(r>qq[i].r)
            toggle(r--);
//        cout<<"sheshe "<<l<<" "<<r<<endl;

        int L= lca( base[qq[i].l], base[qq[i].r] );
        ll pore= 0;

        if( base[qq[i].l]!=L and base[qq[i].r]!=L )
            toggle( st[L] );
        ans[ qq[i].id ]= sum;
//        cout<<ans[ qq[i].id ]<<" hoise\n";
        if( base[qq[i].l]!=L and base[qq[i].r]!=L )
            toggle( st[L] );
    }

    for( int i=1; i<=q; i++ )
        printf("%lld\n",  ans[i] );
}
/*
3 3
1 2 1
1 2
1 3
1 2
1 3
3 1
*/
