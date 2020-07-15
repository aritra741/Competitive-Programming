#include<bits/stdc++.h>
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 1000007
using namespace std;

int arr[mx], tree[4*mx];

void Insert( int node, int l, int r, int i )
{
    if( l>i or r<i )
        return;
    if( l>=i and r<=i )
    {
        tree[node]++;
        return;
    }

    Insert( lchild, l, mid, i );
    Insert( rchild, mid+1, r, i );

    tree[node]= tree[lchild]+tree[rchild];
}

void Remove( int node, int l, int r, int k )
{
    if( l==r )
    {
        tree[node]--;
        return;
    }
    if( tree[lchild]>=k )
        Remove( lchild, l, mid, k );
    else
        Remove( rchild, mid+1, r, k-tree[lchild] );

    tree[node]= tree[lchild]+tree[rchild];
}

int query( int node, int l, int r )
{
    if( l==r )
    {
        if(tree[node]>0)
            return l;
        return 0;
    }

    int q1= query( lchild, l, mid );
    int q2= query( rchild, mid+1, r );

    return max(q1,q2);
}

int main()
{
    int n,q;
    scanf("%d %d", &n, &q);

    for( int i=1;i<=n;i++ )
    {
        int p;
        scanf("%d", &p);

        Insert( 1, 1, n, p );
    }

    while(q--)
    {
        int p;
        scanf("%d", &p);

        if( p>0 )
            Insert( 1, 1, n, p );
        else
            Remove( 1, 1, n, abs(p) );
    }

    printf("%d\n",  query( 1, 1, n ) );
}
