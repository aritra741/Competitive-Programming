#include<bits/stdc++.h>
#define ll long long
#define mx 1000007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

map<ll,int>mp;

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

    if(i<=mid)
        update( lchild, l, mid, i, x );
    else
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

ll rec( ll u )
{
//    cout<<u<<" "<<mp[u]<<endl;
    if( u==1 )
        return 1;

    if( mp[u] )
        return mp[u];

    if(u&1)
        return mp[u]= 1+rec( 3*u+1 );
    return mp[u]= 1+rec( u/2 );
}

int main()
{
    ll tot= 0;

    for( int i=1000000;i>=1;i-- )
        update( 1, 1, mx, i, rec(i) );

    int i,j;

    while( scanf("%d %d", &i, &j)==2 )
    {
        printf("%d %d %d\n", min(i,j), max(i,j), query( 1, 1, mx, i, j ) );
    }
}
