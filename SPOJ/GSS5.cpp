#include <bits/stdc++.h>
#define mx 200007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

struct seg
{
    int suffix, prefix, sum, overlap, best;

    seg()
    {
        sum= prefix= suffix= overlap= best= 0;
    }

    seg( int val )
    {
        sum= prefix= suffix= overlap= best= val;
    }

} tree[4*mx];

int arr[mx];

void merge_node( seg &node, seg left, seg right )
{
    node.sum= left.sum+right.sum;
    node.suffix= max( right.suffix, right.sum+left.suffix );
    node.prefix= max( left.prefix, left.sum+right.prefix );
    node.overlap= left.suffix+right.prefix;
    node.best= max( left.best, right.best );        /// Very Important
    node.best= max(node.best, max( node.sum, max(node.suffix, max( node.prefix, node.overlap ) ) ) );
}

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node]= seg(arr[l]);
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    merge_node( tree[node], tree[lchild], tree[rchild] );
}

seg query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i or l>r )
    {
        seg emp(-100000007);
        emp.sum= 0;             /// Very Important
        return emp;
    }

    if( l>=i and r<=j )
        return tree[node];

    seg q1= query( lchild, l, mid, i, j );
    seg q2= query( rchild, mid+1, r, i, j );

    seg ret;
    merge_node( ret, q1, q2 );

    return ret;
}


int main()
{
    int tc;
    cin>>tc;

    while( tc-- )
    {
        int n;
        scanf("%d", &n);

        for( int i=1;i<=n;i++ )
            scanf("%d", &arr[i]);
        build( 1, 1, n );

        int q;
        scanf("%d", &q);

        while(q--)
        {
            int x1,x2,y1,y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            int ans;

            if( y1<x2 )
            {
                ans= query( 1, 1, n, x1, y1 ).suffix;
                ans+= query( 1, 1, n, y1+1, x2-1 ).sum;
                ans+= query( 1, 1, n, x2, y2 ).prefix;
            }

            else
            {
                ans= query( 1, 1, n, x1, x2-1 ).suffix+query( 1, 1, n, x2, y2 ).prefix;
                ans= max( ans, query( 1, 1, n, y1+1, y2 ).prefix+query( 1, 1, n, x1, y1 ).suffix );
                ans= max( ans, query( 1, 1, n, x2, y1 ).best );
            }

            printf("%d\n", ans);
        }

        for( int i= 0;i<4*mx;i++ )
            tree[i]= seg();
    }
}
