#include <bits/stdc++.h>
#define mx 1000007
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
#define Max(a,b,c,d,e) max( a, max( b, max( c, max( d, e ) ) ) )
using namespace std;

struct sub
{
    int a4, a7, a47, a74;
};

sub tree[4*mx];
int lazy[4*mx];
int arr[mx];

void merge_node( int node, int l, int r )
{
    tree[node].a4= tree[lchild].a4+tree[rchild].a4;
    tree[node].a7= tree[lchild].a7+tree[rchild].a7;
    tree[node].a47= Max(tree[lchild].a47+tree[rchild].a7, tree[lchild].a4+tree[rchild].a47, tree[lchild].a4+tree[rchild].a7, tree[lchild].a4+tree[rchild].a4, tree[lchild].a7+tree[rchild].a7 );
    tree[node].a74= Max(tree[lchild].a74+tree[rchild].a4, tree[lchild].a7+tree[rchild].a74, tree[lchild].a7+tree[rchild].a4, tree[lchild].a4+tree[rchild].a4, tree[lchild].a7+tree[rchild].a7 );
}

void prop( int node, int l, int r )
{
    if(l!=r)
    {
        lazy[lchild]+= lazy[node];
        lazy[rchild]+= lazy[node];
    }

    swap( tree[node].a4, tree[node].a7 );
    swap( tree[node].a74, tree[node].a47 );
    lazy[node]= 0;
}

void build( int node, int l, int r )
{
    if( l==r )
    {
        if( arr[l]==4 )
        {
            tree[node].a4= 1;
            tree[node].a7= 0;
            tree[node].a47= 1;
            tree[node].a74= 1;
        }
        else
        {
            tree[node].a4= 0;
            tree[node].a7= 1;
            tree[node].a47= 1;
            tree[node].a74= 1;
        }
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    merge_node( node, l, r );
}

void update( int node, int l, int r, int i, int j )
{
    if( lazy[node]&1 )
        prop( node, l, r );

    if( l>j or r<i )
        return;

    if( l>=i and r<=j )
    {
        lazy[node]++;

        if( lazy[node]&1 )
            prop( node, l, r );
        return;
    }

    update( lchild, l, mid, i, j );
    update( rchild, mid+1, r, i, j );
    merge_node( node, l, r );
}

int query( int node, int l, int r, int i, int j )
{
    if( lazy[node]&1 )
        prop( node, l, r );
    if( l>j or r<i )
        return 0;

    if( l>=i and r<=j )
        return tree[node].a47;

    int q1= query( lchild, l, mid, i, j );
    int q2= query( rchild, mid+1, r, i, j );

    return q1+q2;
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    for( int i=1;i<=n;i++ )
    {
        char c;
        scanf(" %c", &c);

        arr[i]= c-'0';
    }

    build( 1, 1, n );

    while(m--)
    {
        string s;
        cin>>s;

        if( s=="switch" )
        {
            int i,j;

            scanf("%d %d", &i, &j);

            update( 1, 1, n, i, j );
        }
        else
            printf("%d\n", query( 1, 1, n, 1, n ) );
    }
}

/*
  cout<<" "<<l<<" "<<r<<" "<<tree[node].a4<<" "<<tree[node].a7<<" "<<tree[node].a47<<" "<<tree[node].a74<<endl;
  */
