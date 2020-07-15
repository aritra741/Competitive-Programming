#include <bits/stdc++.h>
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 30007
using namespace std;

string s;
struct
{
    int open, close;
}tree[4*mx];

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
void update( int node, int l, int r, int i )
{
    if( l>i or r<i )
        return;
    if(l==i and r==i)
    {
        if( s[i-1]=='(' )
            s[i-1]=')',
            tree[node].open= 0,
            tree[node].close= 1;
        else
            s[i-1]='(',
            tree[node].open= 1,
            tree[node].close= 0;
        return;
    }

    update( lchild, l, mid, i );
    update( rchild, mid+1, r, i );

    merge_node( node );
}

int main()
{
    for( int t=1;t<=10;t++ )
    {
        int n;
        scanf("%d", &n);

        cin>>s;

        build(1, 1, n);

        int q;
        scanf("%d", &q);
        printf("Test %d:\n", t);

        while(q--)
        {
            int p;
            scanf("%d", &p);

            if(!p)
            {
                if( tree[1].open or tree[1].close )
                    printf("NO\n");
                else
                    printf("YES\n");
            }

            update( 1, 1, n, p );
        }

        memset(tree,0,sizeof(tree));
    }
}
