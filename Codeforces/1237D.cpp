#include <bits/stdc++.h>
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
#define mx 200007
using namespace std;

struct pp
{
    int v,id;
};

int arr[mx];
pp tree[4*mx];

void build( int node, int l, int r )
{
    if(l==r)
    {
        tree[node].v= arr[l];
        tree[node].id= l;
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node].v= min( tree[lchild].v, tree[rchild].v );
    tree[node].id= 0;
}

int query( int node, int l, int r, int i, int j, int x )
{
    if( l>j or r<i )
        return INT_MAX;
    if( l==r )
        return tree[node].id;

    int q1= INT_MAX, q2= q1;

    if( tree[lchild].v<x )
        q1= query( lchild, l, mid, i, j, x );
    if( tree[rchild].v<x )
        q2= query( rchild, mid+1, r, i, j, x );

    return min(q1, q2);
}

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=1;i<=n;i++ )
        scanf("%d", &arr[i]);

    for( int i=1;i<=n;i++ )
        arr[n+i]= arr[i];

    n*= 2;

    build( 1, 1, n );

    for( int i=1;i<=n/2;i++ )
    {
        int ans= query( 1, 1, n, i+1, n, arr[i]/2 );

        cout<<arr[i]<<" "<<ans<<" "<<arr[ans]<<endl;
//        if( ans==INT_MAX )
//            printf("-1 ");
//        else
//            printf("%d ", ans-i);
    }
}
