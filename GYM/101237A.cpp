#include<bits/stdc++.h>
#define mx 1000007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define pii pair<int,int>
#define piii pair< int, pii >
#define ff first
#define ss second
using namespace std;

int tree[4*mx], arr[mx];
int ans[mx];
piii qq[mx];

void update( int node, int l, int r, int i, int val )
{
    if( l>i or r<i )
        return;
    if( l==i and r==i )
    {
        tree[node]= val;
        return;
    }

    update( lchild, l, mid, i, val );
    update( rchild, mid+1, r, i, val );

    tree[node]= min( tree[lchild], tree[rchild] );
}

int query( int node, int l, int r, int i )
{
    if( l==r )
        return l;
    if( tree[lchild]<i )
        return query( lchild, l, mid, i );
    return query( rchild, mid+1, r, i );
}

int main()
{
    memset( tree, -1, sizeof(tree) );

    int n;
    scanf("%d", &n);

    for( int i=1;i<=n;i++ )
        scanf("%d", &arr[i]);

    int q;
    scanf("%d", &q);

    for( int i=0;i<q;i++ )
        scanf("%d %d",&qq[i].ss.ff, &qq[i].ff), qq[i].ss.ss= i;

    sort( qq, qq+q );

    int j= 0;

    for( int i=0;i<q;i++ )
    {
        while( ++j<=qq[i].ff )
            update( 1, 0, mx, arr[j], j );
        j--;
        ans[ qq[i].ss.ss ]= query( 1, 0, mx, qq[i].ss.ff );
    }

    for( int i=0;i<q;i++ )
        printf("%d\n", ans[i]);
}
