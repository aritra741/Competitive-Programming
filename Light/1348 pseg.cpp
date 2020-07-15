#include<bits/stdc++.h>
#define F first
#define ll int
#define N 30007
using namespace std;
struct node
{
    int l,r,val;
    node()
    {
        l=r=val=0;
    } node(int _l,int _r,int _val)
    {
        l=_l,r=_r,val=_val;
    }
} t[20*N]; ///size will be nlogn
int root[N],cnt;
ll a[N];
const int c= 100;
vector<int>adj[N];
int par[N][22], dep[N];

int lca(int u,int v)
{
    if(dep[u]<dep[v])
        swap(u,v);
//    cout<<u<<" "<<v<<" "<<dep[u]<<" "<<dep[v]<<endl;
    for(int k=21; k>=0; k--)
        if(dep[par[u][k]]>=dep[v])
            u=par[u][k];
//    cout<<"agey "<<u<<endl;
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
        t[cur]=node(0,0,0);    ///1 2 2 3 , 3rd number is 3
        ///the code returns k-th unique number in a range l to r if the range were sorted
        return ;
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
//        cout<<"agey chhilo "<<t[cur].val<<endl;
        t[cur].val=t[pre].val+v;
//        cout<<"update hocche "<<b<<" "<<e<<" "<<t[cur].val<<endl;
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
//    cout<<"sheshe "<<b<<" "<<e<<" "<<t[left].val<<" "<<t[right].val<<endl;
}

int query(int u, int v, int upor, int cent, int b, int e, int k)
{
//    cout<<b<<" "<<e<<" "<<k<<" "<<t[t[u].l].val<<" "<<t[t[v].l].val<<" "<<t[t[cent].l].val<<" "<<t[t[upor].l].val<<endl;
//    cout<<u<<" "<<v<<" "<<cent<<" "<<upor<<endl;
    if(b==e)
        return b;
    int cnt= t[t[u].l].val+t[t[v].l].val-t[t[cent].l].val-t[t[upor].l].val;
//    cout<<b<<" "<<e<<" "<<cnt<<" "<<k<<endl;
    int mid=(b+e)/2;
    if(cnt>=k)
        return query(t[u].l,t[v].l,t[upor].l,t[cent].l,b,mid,k);
    else
        return query(t[u].r,t[v].r,t[upor].r,t[cent].r,mid+1,e,k-cnt);
}

void dfs( int u, int pre )
{
    dep[u]= dep[pre]+1;
    root[u]= ++cnt;
//    cout<<u<<" "<<mp[a[u]]<<endl;
//cout<<u<<" "<<a[u]<<" "<<mp[a[u]]<<" "<<t[root[u]].val<<endl;

//cout<<u<<":\n";
    upd(root[pre],root[u],1,1,1,a[u]);

    for( auto v: adj[u] )
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
    int i,j,k,n,m,q,x,l,r;
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        scanf("%d", &a[i]);

    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        u++, v++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    root[0]=++cnt;
    build(root[0],0,c);
    dfs(1,0);

    scanf("%d", &q);

//    cout<<par[2][0]<<endl;
    for( int j=1; j<=21; j++ )
        for( int i=1; i<=n; i++ )
            par[i][j]= par[par[i][j-1]][j-1];

    while(q--)
    {
        int tp,u,v;
        scanf("%d %d %d", &tp, &u, &v);
        u++;

        if(tp)
            upd( root[u], root[u], 1, 1, 1, -a[u] ),
            upd( root[u], root[u], 1, 1, 1, v ),a[u]= v;
        else
        {
            v++;
            int LCA= lca(u,v);
//            cout<<t[ root[u] ].val<<" "<<t[ root[v] ].val<<" "<<t[ root[LCA] ].val<<" "<<t[ root[par[LCA][0]] ].val<<endl;
            printf("%d\n", t[ root[u] ].val+t[ root[v] ].val-t[ root[LCA] ].val- t[ root[par[LCA][0]]].val );
        }
    }
}
