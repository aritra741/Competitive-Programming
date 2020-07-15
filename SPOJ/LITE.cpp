#include <bits/stdc++.h>
#define MX 100005
using namespace std;

int arr[MX];
struct{
    int sum, lazy;
}tree[3*MX];

void update( int node, int l, int r, int i, int j)
{

    if(tree[node].lazy & 1)
    {
        tree[node].sum=(r-l+1)-tree[node].sum;
        tree[node].lazy=0;
        if(l!=r)
            tree[2*node].lazy++, tree[2*node+1].lazy++;
    }

    if( j<l or i>r )
        return;

    if(l>=i and r<=j)
    {
        tree[node].sum=(r-l+1)-tree[node].sum;
        if(l!=r)
            tree[2*node].lazy++, tree[2*node+1].lazy++;
        return;
    }

    int lChild= 2*node;
    int rChild= 2*node+1;
    int mid=(l+r)/2;

    update(lChild, l, mid, i, j);
    update(rChild, mid+1, r, i, j);

    tree[node].sum= tree[lChild].sum+tree[rChild].sum;


}

int query( int node, int l, int r, int i, int j)
{
    if(l>j or r<i)
        return 0;
    if(tree[node].lazy & 1)
    {
        tree[node].sum=(r-l+1)-tree[node].sum;
        tree[node].lazy=0;
        if(l!=r)
            tree[2*node].lazy++, tree[2*node+1].lazy++;
    }

    if(l>=i and r<=j)
    {
        return tree[node].sum;
    }

    int lChild= 2*node;
    int rChild= 2*node+1;
    int mid=(l+r)/2;

    int q1= query( lChild, l, mid, i, j );
    int q2= query( rChild, mid+1, r, i, j);

    return q1+q2;
}

int main()
{
    memset( arr, 0, sizeof(arr) );
    memset( tree, 0, sizeof(tree) );

    int n,m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        int q;
        scanf("%d", &q);

        if(!q)
        {
            int i,j;
            scanf("%d %d", &i, &j);
            update(1, 1, n, i, j);
        }

        else
        {
            int i,j;
            scanf("%d %d", &i, &j);
            int val=query(1, 1, n, i, j);
            printf("%d\n", val);
        }
    }
}
