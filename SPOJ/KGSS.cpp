#include <bits/stdc++.h>
#define mx 100007
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
#define pii pair<int,int>
#define f first
#define s second
#define ll long long
using namespace std;

struct
{
    int big, sbig;
} tree[4*mx];

int arr[mx];

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node].big= arr[l];
        tree[node].sbig= 0;
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    int a[4];
    a[0]= tree[lchild].big;
    a[1]= tree[lchild].sbig;
    a[2]= tree[rchild].big;
    a[3]= tree[rchild].sbig;

    sort( a, a+4 );

    tree[node].big= a[3];
    tree[node].sbig= a[2];
}

void update( int node, int l, int r, int i, int val )
{
    if( l>i or r<i )
        return;
    if( l>=i and r<=i )
    {
        tree[node].big= val;
        tree[node].sbig= 0;
        return;
    }

    update( lchild, l, mid, i, val );
    update( rchild, mid+1, r, i, val );

    int a[4];
    a[0]= tree[lchild].big;
    a[1]= tree[lchild].sbig;
    a[2]= tree[rchild].big;
    a[3]= tree[rchild].sbig;

    sort( a, a+4 );

    tree[node].big= a[3];
    tree[node].sbig= a[2];
}

pii query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return pii( 0,0 );
    if( l>=i and r<=j )
        return pii( tree[node].big, tree[node].sbig );

    pii q1= query( lchild, l, mid, i, j );
    pii q2= query( rchild, mid+1, r, i, j );

    int a[4];
    a[0]= q1.f;
    a[1]= q1.s;
    a[2]= q2.f;
    a[3]= q2.s;

    sort( a, a+4 );

    return pii( a[3], a[2] );
}

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=1;i<=n;i++ )
        scanf("%d", &arr[i]);

    build( 1, 1, n );

    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        char c;
        int i,j;
        cin>>c;
        scanf("%d %d", &i, &j);

        if( c=='Q' )
        {
            pii q= query( 1, 1, n, i, j );

            ll ans= q.f;
            ans+= q.s;

            printf("%lld\n", ans);
        }

        else
        {
            update( 1, 1, n, i, j );
        }
    }
}
