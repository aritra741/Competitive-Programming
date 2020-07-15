#include <bits/stdc++.h>
#define mx 100007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define pii pair<int,int>
using namespace std;

pii arr[mx];
int inp[mx];
vector<int> tree[4*mx];

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node].push_back( arr[l].second );
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    merge( tree[lchild].begin(), tree[lchild].end(), tree[rchild].begin(), tree[rchild].end(), back_inserter(tree[node]) );
}


int query( int node, int l, int r, int i, int j, int k )
{
    if( l==r )
        return tree[node][0];

    auto it= upper_bound( tree[lchild].begin(), tree[lchild].end(), j );
    int tot= it- lower_bound( tree[lchild].begin(), tree[lchild].end(), i );

    if( k>tot )
        return query( rchild, mid+1, r, i, j, k-tot );
    return query( lchild, l, mid, i, j, k );
}


int main()
{
    int n,q;
    scanf("%d %d", &n, &q);

    for( int i=1; i<=n; i++ )
    {
        scanf("%d", &arr[i].first);
        arr[i].second= i;
        inp[i]= arr[i].first;
    }

    sort( arr+1, arr+n+1 );
    build( 1, 1, n );

    while(q--)
    {
        int i,j,k;
        scanf("%d %d %d", &i, &j, &k);

        int ans= query( 1, 1, n, i, j, k );

        printf("%d\n", inp[ans]);
    }
}
