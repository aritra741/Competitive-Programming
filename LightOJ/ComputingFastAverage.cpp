#include <bits/stdc++.h>
#define mx 100007
#define ll long long
using namespace std;

ll tree[4*mx], lazy[4*mx];

void update( int node, int l, int r, int i, int j, ll val )
{
    if( lazy[node]!=-1 )
    {
        tree[node]= (r-l+1)*lazy[node];

        if( l!=r )
            lazy[2*node]= lazy[node],
            lazy[2*node+1]= lazy[node];
        lazy[node]= -1;
    }

    if( l>j or r<i )
        return;
    if( l>=i and r<=j )
    {
        tree[node]= (r-l+1)*val;

        if( l!=r )
            lazy[2*node]= val,
            lazy[2*node+1]= val;
        return;
    }

    update( node*2, l, (l+r)/2, i, j, val  );
    update( node*2+1, 1+(l+r)/2, r, i, j, val  );

    tree[node]= tree[node*2]+tree[node*2+1];
}

ll query( int node, int l, int r, int i, int j )
{
    if( lazy[node]!=-1 )
    {
        tree[node]= (r-l+1)*lazy[node];

        if( l!=r )
            lazy[2*node]= lazy[node],
            lazy[2*node+1]= lazy[node];
        lazy[node]= -1;
    }

    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node];

    ll q1= query( node*2, l, (l+r)/2, i, j );
    ll q2= query( node*2+1, 1+(l+r)/2, r, i, j );

    return q1+q2;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        int n,q;
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", t);

        while(q--)
        {
            int p, i, j;
            scanf("%d %d %d", &p, &i, &j);
            i++, j++;

            if( p==1 )
            {
                ll v;
                scanf("%lld", &v);

                update( 1, 1, n, i, j, v );
            }

            else
            {
                ll sum= query( 1, 1, n, i, j );
                ll num= j-i+1;

                ll g= __gcd( num, sum );

                sum/= g;
                num/= g;

                printf("%lld", sum);

                if(sum and num!=1)
                    printf("/%lld", num);
                printf("\n");
            }
        }

        memset( tree, 0, sizeof(tree) );
        memset( lazy, -1, sizeof(lazy) );
    }
}
