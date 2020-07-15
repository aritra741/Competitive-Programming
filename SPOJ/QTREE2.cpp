#include<bits/stdc++.h>
#define F first
#define ll int
#define N 10007
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
} t[20*N][2]; ///size will be nlogn
int root[N],cnt,c,a[N];
map<ll,ll>ulta,mp;
vector<int>adj[N], cost[N];
int par[N][22], dep[N];
int lca(int u,int v)
{
    if(dep[u]<dep[v])
        swap(u,v);
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
        t[cur][0]=node(0,0,0);
        t[cur][1]=node(0,0,0);
        return;
    }
    int left,right,mid=(b+e)/2;
    t[cur][0].l=left=++cnt;
    t[cur][0].r=right=++cnt;
    t[cur][1].l=left=++cnt;
    t[cur][1].r=right=++cnt;
    build(left,b,mid);
    build(right,mid+1,e);
    t[cur][0].val=t[left][0].val+t[right][0].val;
    t[cur][1].val=t[left][1].val+t[right][1].val;
}
void upd(int pre,int cur,int b,int e,int i,int v)
{
    if(i<b||i>e)
        return;
    if(b==e)
    {
        t[cur][0].val= v;
        t[cur][1].val= t[pre][1].val+v;
        return;
    }

    int left,right,mid=(b+e)/2;
    if(i<=mid)
    {
        t[cur][0].r=right=t[pre][0].r;
        t[cur][0].l=left=++cnt;
        t[cur][1].r=right=t[pre][1].r;
        t[cur][1].l=left=++cnt;

        upd(t[pre][0].l,t[cur][0].l,b,mid,i,v);
        upd(t[pre][1].l,t[cur][1].l,b,mid,i,v);
    }
    else
    {
        t[cur][0].l=left=t[pre][0].l;
        t[cur][0].r=right=++cnt;
        t[cur][1].l=left=t[pre][1].l;
        t[cur][1].r=right=++cnt;
        upd(t[pre][0].r,t[cur][0].r,mid+1,e,i,v);
    }
    t[cur][0].val=t[left][0].val+t[right][0].val;
    t[cur][1].val=t[left][1].val+t[right][1].val;
}
int query(int u, int v, int upor, int cent, int b, int e, int k)
{
    int mid=(b+e)/2;
    if(b==e)
        return b;
    int cnt=t[t[u][0].l][0].val+t[t[v][0].l][0].val-t[t[cent][0].l][0].val-t[t[upor][0].l][0].val;
    if(cnt>=k)
        return query(t[u][0].l,t[v][0].l,t[upor][0].l,t[cent][0].l,b,mid,k);
    return query(t[u][0].r,t[v][0].r,t[upor][0].r,t[cent][0].r,mid+1,e,k-cnt);
}

void dfs( int u, int pre )
{
    dep[u]=dep[pre]+1;
    root[u]=++cnt;
    upd(root[pre],root[u],1,c,u,1);
    for(auto v:adj[u])
    {
        if(v==pre)
            continue;
        par[v][0]= u;
        dfs(v,u);
    }
}

void agey( int u, int pre )
{
    for(int i=0; i<adj[u].size(); i++)
    {
        int v= adj[u][i];
        if(v==pre)
            continue;
        a[v]= cost[u][i];
        mp[ a[v] ];
        agey(v,u);
    }
}
//void onno_query( int node, int b, int e )
//{
////    cout<<b<<" "<<e<<" "<<t[node].val<<endl;
//    if( b==e )
//        return;
//    int mid= (b+e)/2;
//    onno_query( t[node].l, b, mid );
//    onno_query( t[node].r, mid+1, e );
//}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int i,j,k,n,m,q,t,x,l,r;
        scanf("%d", &n);

        for(int i=1; i<n; i++)
        {
            int u,v,c;
            scanf("%d %d %d", &u, &v, &c);

            adj[u].push_back(v);
            cost[u].push_back(c);
            adj[v].push_back(u);
            cost[v].push_back(c);
        }

        agey(1,0);
        a[1]= 0;
        mp[0];

        for(auto x:mp)
            mp[x.F]=++c,ulta[c]=x.F;

        root[0]=++cnt;
        build(root[0],1,c);
        dfs(1,0);

//    cout<<par[2][0]<<endl;
        for( int j=1; j<=21; j++ )
            for( int i=1; i<=n; i++ )
                par[i][j]= par[par[i][j-1]][j-1];

        while(1)
        {
            char s[5];
            scanf("%s", s);

            if( s[0]=='K' )
            {
                scanf("%d %d %d", &l, &r, &k);
                int LCA= lca(l,r);

//        cout<<LCA<<endl;

                printf("%d\n", ulta[query(root[l],root[r],root[par[LCA][0]], root[LCA], 1,c,k)]);
            }
        }
    }
}
