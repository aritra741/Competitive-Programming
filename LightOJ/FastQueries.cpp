#include <bits/stdc++.h>
#define mx 100007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

int tree[4*mx], arr[mx], idx[mx];

struct Q
{
    int l, r, id;
} quarr[50007];

bool cmp( const Q &a, const Q &b )
{
    return a.r<b.r;
}

void update( int node, int l, int r, int i, int val )
{
    if(l>i or r<i)
        return;
    if( l==r )
    {
        tree[node]= val;
        return;
    }

    update( lchild, l, mid, i, val );
    update( rchild, mid+1, r, i, val );

    tree[node]= tree[lchild]+tree[rchild];
}

int query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node];

    int q1= query( lchild, l, mid, i, j );
    int q2= query( rchild, mid+1, r, i, j );

    return q1+q2;
}

int main()
{
    int tc;
    cin>>tc;

    for( int t=1; t<=tc; t++ )
    {
        int n,q;
        scanf("%d %d", &n, &q);

        for( int i=1; i<=n; i++ )
            scanf("%d", &arr[i]);

        for( int i=1;i<=q;i++ )
        {
            scanf("%d %d", &quarr[i].l, &quarr[i].r);
            quarr[i].id= i;
        }

        printf("Case %d:\n", t);

        sort( quarr+1, quarr+q+1, cmp );

        int k= 1;
        int out[q];

        for( int i=1; i<=n; i++ )
        {
            if( idx[arr[i]] )
                update( 1, 1, n, idx[arr[i]], 0 );
            idx[arr[i]]= i;
            update( 1, 1, n, i, 1 );

            while( quarr[k].r==i and k<=q )
            {
                int l= quarr[k].l;
                int ans= query( 1, 1, n, 1, quarr[k].r )-query( 1, 1, n, 1, l-1 );

                out[quarr[k].id]= ans;
                k++;
            }
        }

        for( int i=1;i<=q;i++ )
            printf("%d\n", out[i]);

        memset( quarr, 0, sizeof(quarr) );
        memset( idx, 0, sizeof(idx) );
    }
}
