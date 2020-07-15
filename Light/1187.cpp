#include<bits/stdc++.h>
#define ll long long
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 100007
using namespace std;

int ans[mx];
ll tree[mx*4][2], lazy[4*mx];
int arr[mx];

void prop( int node, int l, int r )
{
    if(!lazy[node])
        return;

    tree[node][0]+= lazy[node];
    if(l!=r)
    {
        lazy[lchild]+= lazy[node];
        lazy[rchild]+= lazy[node];
    }
    lazy[node]= 0;
}

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node][0]= arr[l];
        tree[node][1]= l;
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    if( tree[rchild][0]<=tree[lchild][0] )
        tree[node][0]= tree[rchild][0],
        tree[node][1]= tree[rchild][1];
    else
        tree[node][0]= tree[lchild][0],
        tree[node][1]= tree[lchild][1];
}

void update( int node, int l, int r, int i, int j, ll v )
{
    prop(node,l,r);
    if( l>j or r<i )
        return;
    if( l>=i and r<=j )
    {
        lazy[node]+= v;
        prop(node,l,r);
        return;
    }

    update( lchild, l, mid, i, j, v );
    update( rchild, mid+1, r, i, j, v );

    if( tree[rchild][0]<=tree[lchild][0] )
        tree[node][0]= tree[rchild][0],
        tree[node][1]= tree[rchild][1];
    else
        tree[node][0]= tree[lchild][0],
        tree[node][1]= tree[lchild][1];
}

void traverse( int node, int l, int r )
{
    prop(node,l,r);

    if(l==r)
        return;

    traverse( lchild, l, mid );
    traverse( rchild, mid+1, r );
}

pii query( int node, int l, int r, int i, int j )
{
    prop(node,l,r);

    if(l>j or r<i)
        return {2e9,-2e9};

    if(l>=i and r<=j)
    {
        return {tree[node][0], tree[node][1]};
    }

    pii q1= query( rchild, mid+1, r, i, j );
    pii q2= query( lchild, l, mid, i, j );

    if( q1.ff<=q2.ff )
        return q1;
    return q2;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
//        memset( tree, 0, sizeof(tree) );
        memset( lazy, 0, sizeof(lazy) );

        int n;
        scanf("%d", &n);

        for( int i=1; i<=n; i++ )
            scanf("%d", &arr[i]);

        build( 1, 1, n );

        int x= n;

        for( int i=n; i>=1; i-- )
        {
            x= i;

            int pos= query( 1, 1, n, 1, n ).ss;

            if( pos==1 )
                break;

            update( 1, 1, n, pos, pos, 2e9 );
            if(pos<n)
                update( 1, 1, n, pos+1, n, -1 );
        }

        printf("Case %d: %d\n", t, x);
    }
}
