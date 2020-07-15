#include <bits/stdc++.h>
#define ll long long
#define MX 100007
using namespace std;

ll arr[MX];
struct{
    ll sum, lazy;
}tree[3*MX];

void update( int node, int l, int r, int i, int j, ll val )
{
    if(tree[node].lazy)
    {
        tree[node].sum+= (r-l+1)*tree[node].lazy;
        if(l!=r)
            {
                tree[2*node+2].lazy+=tree[node].lazy;
                tree[2*node+1].lazy+=tree[node].lazy;
            }
        tree[node].lazy=0;
    }

    if(l>j or r<i)
        return;
    if(l>=i and r<=j)
        {
            tree[node].sum+= (r-l+1)*val;
            if(l!=r)
            {
                tree[2*node+2].lazy+=val;
                tree[2*node+1].lazy+=val;
            }

            return;
        }

    int lChild=2*node+1;
    int rChild=2*node+2;
    int mid=(r+l)/2;

    update( lChild, l, mid, i, j, val );
    update( rChild, mid+1, r, i, j, val );

    tree[node].sum=tree[lChild].sum+tree[rChild].sum;
}

ll query( int node, int l, int r, int i, int j )
{
    if(j<l or i>r)
        return 0;

    if(tree[node].lazy)
    {
        tree[node].sum+= (r-l+1)*tree[node].lazy;
        if(l!=r)
        {
            tree[2*node+2].lazy+=tree[node].lazy;
            tree[2*node+1].lazy+=tree[node].lazy;
        }
        tree[node].lazy=0;
    }

    if(l>=i and r<=j)
        return tree[node].sum;

    int lChild=2*node+1;
    int rChild=2*node+2;
    int mid=(r+l)/2;

    ll q1=query( lChild, l, mid, i, j );
    ll q2=query( rChild, mid+1, r, i, j );

    return q1+q2;
}

int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        memset(arr, 0, sizeof(arr));
        memset(tree, 0, sizeof(tree));
        printf("Case %d:\n", t);
        ll n, q;
        scanf("%lld %lld", &n, &q);

        while(q--)
        {
            int type;
            scanf("%d", &type);
            getchar();
            if(type)
            {
                int l,r;
                scanf("%d %d", &l, &r);
                ll ans= query( 0, 0, n-1, l, r );
                printf("%lld\n", ans);
            }

            else
            {
                int l, r;
                ll val;
                scanf("%d %d %lld", &l, &r, &val);
                update(0, 0, n-1, l, r, val);
            }
        }
    }
}
