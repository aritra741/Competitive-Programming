#include<bits/stdc++.h>
#define mx 200007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

int tree[4*mx], lazy[4*mx];
int arr[mx];

void prop( int node, int l, int r )
{
//    cout<<l<<" "<<r<<" "<<tree[lchild]<<" "<<tree[rchild]<<" "<<tree[node]<<endl;
    if( l!=r )
    {
        if( tree[lchild]<lazy[node] and lazy[lchild]<lazy[node] )
            lazy[lchild]= lazy[node];
        if( tree[rchild]<lazy[node] and lazy[rchild]<lazy[node] )
            lazy[rchild]= lazy[node];
    }

    tree[node]= max( tree[node], lazy[node] );
    lazy[node]= 0;
}

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node]= arr[l];
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node]= min( tree[lchild], tree[rchild] );
}

void upd1( int node, int l, int r, int i, int x )
{
    prop( node, l, r );

    if( l>i or r<i )
        return;

    if( l==r and l==i )
    {
        tree[node]= x;
        return;
    }

    upd1( lchild, l, mid, i, x );
    upd1( rchild, mid+1, r, i, x );

    tree[node]= min( tree[lchild], tree[rchild] );
}

void upd2( int node, int l, int r, int i, int j, int x )
{
    prop( node, l, r );

    if( l>=i and r<=j )
    {
        lazy[node]= max( lazy[node], x ) ;
        prop( node, l, r );

        return;
    }

    upd2( lchild, l, mid, i, j, x );
    upd2( rchild, mid+1, r, i, j, x );

    tree[node]= min( tree[lchild], tree[rchild] );
}

int query( int node, int l, int r, int i )
{
    prop( node, l, r );
    if( l>i or r<i )
        return 2e9;
    if( l==i and l==r )
        return tree[node];

    if( i<=mid )
        return query( lchild, l, mid, i );
    return query( rchild, mid+1, r, i );
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for( int i=1; i<=n; i++ )
        cin>> arr[i];

    build( 1, 1, n );

    int q;
    cin>>q;

    while(q--)
    {
        int tp;
        cin>>tp;

        if(tp==1)
        {
            int i, x;
            cin>>i>>x;

            upd1( 1, 1, n, i, x );
        }
        else
        {
            int x;
            cin>>x;

            upd2( 1, 1, n, 1, n, x );
        }
    }

    for( int i=1; i<=n; i++ )
        cout<< query( 1, 1, n, i ) <<" ";
}
