#include<bits/stdc++.h>
#define mx 100007
#define k 320
#define sf(x) scanf("%d", &x)
#define pf(x) printf("%d\n", x)
using namespace std;

vector<int> adj[mx];
int node[mx], reach[mx], cnt[mx];
int cnt_er_cnt[mx];
int col[mx];
bool vis[mx];
int idx[mx];
int ans[mx];
int id= 1;
int sum;

struct query
{
    int l,r,id,koto;
}qq[mx];

bool cmp(query &a, query &b){
  if (a.l/k != b.l/k) return a.l<b.l;
  return a.l/k%2?a.r>b.r:a.r<b.r;
}

void dfs( int u )
{
    vis[u]= 1;
    node[id++]= u;

    for( auto v: adj[u] )
    {
        if(vis[v])
            continue;

        dfs(v);
    }

    reach[u]= id-1;
}

void jog( int x )
{
    if(!x)
        return;
    cnt[ col[x] ]++;
    if(cnt[ col[x] ]>=0)
        cnt_er_cnt[ cnt[ col[x] ] ]++;
}

void baad( int x )
{
    if(!x)
        return;
    if(cnt[ col[x] ]>=0)
        cnt_er_cnt[ cnt[ col[x] ] ]--;
    cnt[ col[x] ]--;
}

int main()
{
    int n,q;
    sf(n);
    sf(q);

    for( int i=1;i<=n;i++ )
        sf(col[i]);

    for( int i=1;i<n;i++ )
    {
        int a,b;
        sf(a);
        sf(b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for( int i=0;i<q;i++ )
    {
        int p;
        sf(p);
        qq[i].l= node[p];
        sf(qq[i].koto);
        qq[i].id= i+1;
        qq[i].r= reach[p];
    }

    sort( qq, qq+q, cmp );

    int l= 0, r= 0;

    for( int i=0;i<q;i++ )
    {
        while(l<qq[i].l) baad( node[l++] );
        while(r>qq[i].r) baad( node[r--] );
        while(l>qq[i].l) jog( node[--l] );
        while(r<qq[i].r) jog( node[++r] );

        ans[qq[i].id]= cnt_er_cnt[ qq[i].koto ];
    }

    for( int i=1;i<=q;i++ )
        pf(ans[i]);
}
