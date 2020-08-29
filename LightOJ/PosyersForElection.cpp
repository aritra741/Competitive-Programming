#include <bits/stdc++.h>
#define mx 2*100007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

int tree[4*mx], arr[mx];

void update( int node, int l, int r, int i, int j, int val )
{
    if( l>j or r<i )
        return;
    if( tree[node] )
        if(l!=r)
        tree[lchild]= tree[node],
        tree[rchild]= tree[node],
        tree[node]= 0;

    if( l>=i and r<=j )
    {
        tree[node]= val;
        return;
    }

    update( lchild, l, mid, i, j, val );
    update( rchild, mid+1, r, i, j, val );
}

int query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0;
    if( tree[node] )
    {
        if(l!=r)
            tree[lchild]= tree[node],
            tree[rchild]= tree[node],
            tree[node]= 0;
    }

    if( l==i and r==j )
        return tree[node];

    int q1= query( lchild, l, mid, i, j );
    int q2= query( rchild, mid+1, r, i, j );

    return q1+q2;
}


int main()
{
    int tc;
    cin>>tc;

    for( int t= 1;t<=tc;t++ )
    {
        int n;
        scanf("%d", &n);

        int Mx= 1;

        for( int i=1;i<=n;i++ )
        {
            int l,r;
            scanf("%d %d", &l, &r);
            Mx= max( Mx, r );

            update( 1, 1, mx, l, r, i );
        }

        set<int> st;

        for( int i=1;i<=Mx;i++ )
        {
            int q= query( 1, 1, mx, i, i );

            if(q)
                st.insert(q);
        }

        printf("Case %d: %d\n", t, (int)st.size());

        memset( tree, 0, sizeof(tree) );
    }
}
