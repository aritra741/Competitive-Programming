#include <bits/stdc++.h>
#define ll long long
#define mx 100007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

ll tree[4*mx], arr[mx];

void build( int node, int l, int r )
{
    if( l==r )
    {
        //cout<<l<<" "<<arr[l]<<endl;
        tree[node]= arr[l];
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node]= tree[lchild]+tree[rchild];
}

void update( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return;
    if( tree[node]==r-l+1 )
        return;
    if( l==r )
    {
        tree[node]= sqrt(tree[node]);
        return;
    }

    update( lchild, l, mid, i, j );
    update( rchild, mid+1, r, i, j );

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
    int tc= 1;

    while( scanf("%d", &n)==1 )
    {
        printf("Case #%d:\n", tc++);

        for( int i=1;i<=n;i++ )
            scanf("%lld", &arr[i]);

        build( 1, 1, n );

        int q;
        scanf("%d", &q);

        while(q--)
        {
            int tp, i, j;
            scanf("%d %d %d", &tp, &i, &j);

            if( i>j )
                swap( i,j );
            if( tp )
            {
                ll ans= query( 1, 1, n, i, j );

                printf("%lld\n", ans);
            }

            else
                update( 1, 1, n, i, j );
        }
    }
}
