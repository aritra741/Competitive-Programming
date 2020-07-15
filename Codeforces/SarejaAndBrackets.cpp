#include <bits/stdc++.h>
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define pii pair<int, int>
#define mx 1000007
using namespace std;

string s;
struct
{
    int open, close;
} tree[4*mx];

void merge_node( int node )
{
    int mn= min(tree[lchild].open, tree[rchild].close);
    tree[node].open= tree[lchild].open+tree[rchild].open-mn;
    tree[node].close= tree[lchild].close+tree[rchild].close-mn;
}

void build( int node, int l, int r )
{
    if( l==r )
    {
        if( s[l-1]=='(' )
            tree[node].open= 1,
            tree[node].close= 0;
        else
            tree[node].open= 0,
            tree[node].close= 1;
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    merge_node(node);
}

pii query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return pii(0,0);
    if( l>=i and r<=j )
        return pii(tree[node].open,tree[node].close);

    pii q1= query( lchild, l, mid, i, j );
    pii q2= query( rchild, mid+1, r, i, j );

    int mn= min(q1.first,q2.second);
    int retopen= q1.first+q2.first-mn;
    int retclose= q1.second+q2.second-mn;

    return pii(retopen,retclose);
}

int main()
{
    cin>>s;
    int n= s.size();

    build(1, 1, n);

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int i,j;
        scanf("%d %d", &i, &j);

        pii ans= query( 1, 1, n, i, j );
        int out= j-i+1-ans.first-ans.second;

        printf("%d\n", out);
    }

}

