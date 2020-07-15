#include <bits/stdc++.h>
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 100007
#define ll long long
using namespace std;

ll tree[4*mx], arr[mx];

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node]=(arr[l]>0)?arr[l]:0;
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node]= tree[lchild]+tree[rchild];
}

ll query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0LL;
    if( l>=i and r<=j )
        return tree[node];

    ll q1= query( lchild, l, mid, i, j );
    ll q2= query( rchild, mid+1, r, i, j );

    return q1+q2;
}

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=1;i<=n;i++ )
        scanf("%lld", &arr[i]);

    build( 1, 1, n );

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int i,j;
        scanf("%d %d", &i, &j);

        ll ans= query( 1, 1, n, i, j );

        printf("%lld\n", ans);
    }
}
