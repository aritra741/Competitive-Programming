#include<bits/stdc++.h>
#define F first
#define ll int
#define N 120007
using namespace std;
#include<bits/stdc++.h>
#define F first
#define ll int
#define N 120007
//#define mid (b+e)/2
using namespace std;
struct node
{
    int l,r,val;
    node()
    {
        l=r=val=0;
    }
    node(int _l,int _r,int _val)
    {
        l=_l,r=_r,val=_val;
    }
} t[20*N]; ///size will be nlogn
int root[N],cnt,c,a[N];
map<ll,ll>ulta,mp;
vector<int>adj[N];
int par[N][22], dep[N];
int lca(int u,int v)
{
    if(lvl[u]<lvl[v])
        swap(u,v);
    for(int k=21; k>=0; k--)
        if(lvl[par[u][k]]>=lvl[v])
            u=par[u][k];
    if(u==v)
        return u;
    for(int k=21; k>=0; k--)
        if(par[u][k]!=par[v][k])
            u=par[u][k],v=par[v][k];
    return par[u][0];
}

void build(int cur,int b,int e)
{
    if(b==e)
    {
        t[cur]=node(0,0,0);
        return;
    }
    int left,right,mid=(b+e)/2;
    t[cur].l=left=++cnt;
    t[cur].r=right=++cnt;
    build(left,b,mid);
    build(right,mid+1,e);
    t[cur].val=t[left].val+t[right].val;
}
void upd(int pre,int cur,int b,int e,int i,int v)
{
    if(i<b||i>e)
        return;
    if(b==e)
    {
        t[cur].val= t[pre].val+v;
        return;
    }
    int left,right,mid=(b+e)/2;
    if(i<=mid)
    {
        t[cur].r=right=t[pre].r;
        t[cur].l=left=++cnt;
        upd(t[pre].l,t[cur].l,b,mid,i,v);
    }
    else
    {
        t[cur].l=left=t[pre].l;
        t[cur].r=right=++cnt;
        upd(t[pre].r,t[cur].r,mid+1,e,i,v);
    }
    t[cur].val=t[left].val+t[right].val;
}
int query(int u, int v, int upor, int cent, int b, int e, int k)
{
    int mid=(b+e)/2;
    if(b==e)
        return b;
    int cnt=t[t[u].l].val+t[t[v].l].val-t[t[cent].l].val-t[t[upor].l].val;
    if(cnt>=k)
        return query(t[u].l,t[v].l,t[upor].l,t[cent].l,b,mid,k);
    return query(t[u].r,t[v].r,t[upor].r,t[cent].r,mid+1,e,k-cnt);
}
void dfs( int u, int pre )
{
    lvl[u]=dep[pre]+1;
    root[u]=++cnt;
    upd(root[pre],root[u],1,c,mp[a[u]],1);
    for(auto v:adj[u])
    {
        if(v==pre)
            continue;
        par[v][0]= u;
        dfs(v,u);
    }
}

void onno_query( int node, int b, int e )
{
//    cout<<b<<" "<<e<<" "<<t[node].val<<endl;
    if( b==e )
        return;
    int mid= (b+e)/2;
    onno_query( t[node].l, b, mid );
    onno_query( t[node].r, mid+1, e );
}

int main()
{
    int i,j,k,n,m,q,t,x,l,r;
    scanf("%d %d", &n, &q);

    for(i=1; i<=n; i++)
        scanf("%d", &a[i]), mp[a[i]];
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d %d", &u, &v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(auto x:mp)
        mp[x.F]=++c,ulta[c]=x.F;

    root[0]=++cnt;
    build(root[0],1,c);
    dfs(1,0);

//    cout<<par[2][0]<<endl;
    for( int j=1; j<=21; j++ )
        for( int i=1; i<=n; i++ )
            par[i][j]= par[par[i][j-1]][j-1];

    while(q--)
    {
        scanf("%d %d %d", &l, &r, &k);
        int LCA= lca(l,r);

//        cout<<LCA<<endl;

        printf("%d\n", ulta[query(root[l],root[r],root[par[LCA][0]], root[LCA], 1,c,k)]);
    }
}

