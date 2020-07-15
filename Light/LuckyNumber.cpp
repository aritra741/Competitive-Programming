#include <bits/stdc++.h>
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 1429500
using namespace std;

int tree[4*mx], ans[100007];

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node]= (l&1);
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node]= tree[lchild]+tree[rchild];
}

int query( int node, int l, int r, int k )
{
    if( l==r )
        return l;

    if( k<=tree[lchild] )
        return query( lchild, l, mid, k );

    return query( rchild, mid+1, r, k-tree[lchild] );
}

void update( int node, int l, int r, int k )
{
    if( l==r )
    {
        tree[node]= 0;
        return;
    }

    if( k<=tree[lchild] )
        update( lchild, l, mid, k );
    else
        update( rchild, mid+1, r, k-tree[lchild] );

    tree[node]= tree[lchild]+tree[rchild];
}

void init()
{
    build(1, 1, mx);
    ans[1]= 1;

    for( int i=2;i<=100000;i++ )
    {
        int ith_element= query( 1, 1, mx, i );
        ans[i]= ith_element;

        int lim= (mx/ith_element)*ith_element;
        for( ;lim>=ith_element;lim-= ith_element )
            update( 1, 1, mx, lim );
    }
}

int main()
{
    init();
    int tc;
    cin>>tc;

    for( int t=1;t<=tc;t++ )
    {
        int n;
        scanf("%d", &n);

        printf("Case %d: %d\n", t, ans[n]);
    }
}
