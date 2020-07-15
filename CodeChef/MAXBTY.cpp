#include<bits/stdc++.h>
#define ll long long
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 100007
using namespace std;

ll arr[mx];

struct node
{
    ll pref, suff, sum;

}tree[4*mx];

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node].pref= tree[node].suff= tree[node].sum= arr[l];
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node].pref= max( tree[lchild].pref, tree[lchild].sum+tree[rchild].pref );
    tree[node].suff= max( tree[rchild].suff, tree[rchild].sum+tree[lchild].suff );
    tree[node].sum= tree[lchild].sum+tree[rchild].sum;
}

void update( int node, int l, int r, int x, ll v )
{
    if( l>x or r<x )
        return;
    if( l>=x and r<=x )
    {
        tree[node].pref= tree[node].suff= tree[node].sum= v;
        return;
    }

    update( lchild, l, mid, x, v );
    update( rchild, mid+1, r, x, v );

    tree[node].pref= max( tree[lchild].pref, tree[lchild].sum+tree[rchild].pref );
    tree[node].suff= max( tree[rchild].suff, tree[rchild].sum+tree[lchild].suff );
    tree[node].sum= tree[lchild].sum+tree[rchild].sum;
}

ll sumquery( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node].sum;

    ll q1= sumquery( lchild, l, mid, i, j );
    ll q2= sumquery( rchild, mid+1, r, i, j );

    return q1+q2;
}

ll prefquery( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node].pref;

    ll baameboro= prefquery( lchild, l, mid, i, j );
    ll baameshob= sumquery( lchild, l, mid, i, j );
    ll daaneboro= prefquery( rchild, mid+1, r, i, j );

//    cout<<l<<" "<<r<<" "<<max(baameboro, daaneboro+baameshob)<<endl;
    return max(baameboro, daaneboro+baameshob);
}

ll suffquery( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node].suff;

    ll daaneboro= suffquery( rchild, mid+1, r, i, j );
    ll daaneshob= sumquery( rchild, mid+1, r, i, j );
    ll baameboro= suffquery( lchild, l, mid, i, j );

    return max( daaneboro, daaneshob+baameboro );
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n,q;
        scanf("%d %d", &n, &q);

        for( int i=1;i<=n;i++ )
            scanf("%lld", &arr[i]);

        build( 1, 1, n );

        while(q--)
        {
            char c[5];
            scanf("%s", c);

            if(c[0]=='Q')
            {
                int x,y;
                scanf("%d %d", &x, &y);

                ll agey= max(0LL,suffquery( 1, 1, n, 1, x-1 ));
                ll pore= max(0LL,prefquery( 1, 1, n, y+1, n ));
                ll eikhane= sumquery( 1, 1, n, x, y );
//                cout<<agey<<" "<<pore<<" "<<eikhane<<endl;

                printf("%lld\n", agey+pore+eikhane);
            }
            else
            {
                ll x,v;
                scanf("%lld %lld", &x, &v);

                update( 1, 1, n, x, v );
            }
        }
    }
}
