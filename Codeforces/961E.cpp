#include<bits/stdc++.h>
#define ll long long
#define F first
#define N 200007
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
} t[40*N]; ///size will be nlogn
int root[N],a[N],cnt;
void build(int cur,int b,int e)
{
    if(b==e)
    {
        t[cur]=node(0,0,0);
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
        t[cur].val=t[pre].val+v;
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
int query(int pre,int cur,int b,int e,int l,int r)
{
    if(b>r or e<l)
        return 0;

    int cnt= t[cur].val-t[pre].val;
    int mid=(b+e)/2;
    if(b>=l and e<=r)
        return cnt;
    int q1= query(t[pre].l,t[cur].l,b,mid,l,r);
    int q2= query(t[pre].r,t[cur].r,mid+1,e,l,r);

    return q1+q2;
}

int main()
{
    int i,j,k,n,m,q,x,l,r,c=0;
    map<int,int>mp;
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        scanf("%d", &a[i]),mp[a[i]], mp[i];

    for(auto x:mp)
        mp[x.F]=++c;

    root[0]=++cnt;
    build(root[0],1,c);

    for(i=1; i<=n; i++)
    {
        root[i]=++cnt;
        upd(root[i-1],root[i],1,c,mp[a[i]],1);
    }

    ll ans= 0;

    for( int i=1;i<=n;i++ )
        ans+= query( root[0], root[min( i-1, mp[a[i]] )], 1, c, mp[i], c );

    printf("%lld\n", ans);
}
