#include <bits/stdc++.h>
#define mx 100007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

int lazy[4*mx];

struct
{
    int one, zero, two;
} tree[4*mx] ;

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node].zero= 1;
        tree[node].one= 0;
        tree[node].two= 0;

        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node].zero= tree[lchild].zero+tree[rchild].zero;
}

void update_node( int node )
{
    int one= tree[node].one;
    int two= tree[node].two;
    int zero= tree[node].zero;

    tree[node].one= zero;
    tree[node].two= one;
    tree[node].zero= two;
}

void update( int node, int l, int r, int i, int j )
{
    //  cout<<l<<" "<<r<<endl;
    if( lazy[node] )
    {
        int rem= lazy[node]%3;

        while(rem--)
        {
            update_node(node);
        }

        if( l!=r )
        {
            lazy[lchild]+= lazy[node]%3;
            lazy[rchild]+= lazy[node]%3;
        }

        lazy[node]= 0;
    }

    if( l>j or r<i )
        return;

    if( l>=i and r<=j )
    {
        update_node(node);

        if(l!=r)
        {
            lazy[lchild]++ ;
            lazy[rchild]++;
        }

        return;
    }

    update( lchild, l, mid, i, j );
    update( rchild, mid+1, r, i, j );

    tree[node].zero= tree[lchild].zero+tree[rchild].zero;
    tree[node].one= tree[lchild].one+tree[rchild].one;
    tree[node].two= tree[lchild].two+tree[rchild].two;
}

int query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0;

    if( lazy[node] )
    {
        int rem= lazy[node]%3;

        while(rem--)
        {
            update_node(node);
        }

        if( l!=r )
        {
            lazy[lchild]+= lazy[node]%3;
            lazy[rchild]+= lazy[node]%3;
        }

        lazy[node]= 0;
    }

    if( l>=i and r<=j )
        return tree[node].zero;

    int q1= query( lchild, l, mid, i, j );
    int q2= query( rchild, mid+1, r, i, j );

    return q1+q2;
}

int main()
{
    int tc;
    cin>>tc;

    for( int t=1; t<=tc; t++ )
    {
        int n,q;
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", t);

        build( 1, 1, n );

        while(q--)
        {
            int p, i, j;
            scanf("%d %d %d", &p, &i, &j);
            i++, j++;

            if(p==0)
                update( 1, 1, n, i, j );
            else
                printf("%d\n", query( 1, 1, n, i, j ));
        }

        memset( tree,0,sizeof(tree) );
        memset( lazy,0,sizeof(lazy) );
    }
}
