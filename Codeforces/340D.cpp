#include<bits/stdc++.h>
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 100007
using namespace std;

int tree[4*mx];

void update( int node, int l, int r, int i, int x )
{
    if( l>i or r<i )
        return;
    if( l>=i and r<=i )
    {
        tree[node]= x;
        return;
    }

    update( lchild, l, mid, i, x );
    update( rchild, mid+1, r, i, x );

    tree[node]= max( tree[lchild], tree[rchild] );
}

int query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node];

    int q1= query( lchild, l, mid, i, j );
    int q2= query( rchild, mid+1, r, i, j );

    return max(q1,q2);
}

int main()
{
    int n;
    cin>>n;

    int ans= 0;

    for( int i=0;i<n;i++ )
    {
        int p,x= 0;
        cin>>p;

        if(p>1)
            x= query( 1, 1, n, 1, p-1 );

        ans= max( ans, x+1 );

        update( 1, 1, n, p, x+1 );
    }

    cout<< ans <<endl;
}
