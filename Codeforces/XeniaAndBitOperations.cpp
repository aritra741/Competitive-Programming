#include <bits/stdc++.h>
#define MX 150000
using namespace std;

int arr[MX], tree[MX*4];
int level=0;

void build( int node, int l, int r )
{
    if(l==r)
        {
            tree[node]= arr[l];
            level=0;
            return;
        }

    int mid= (l+r)/2;
    int lChild= 2*node;
    int rChild= 2*node+1;

    build( lChild, l, mid );
    build( rChild, mid+1, r );

    level++;

    if( level & 1 )
        tree[node]= tree[lChild] | tree[rChild];
    else
        tree[node]= tree[lChild] ^ tree[rChild];
}

void update( int node, int l, int r, int i, int val )
{
    if(r<i or l>i)
        return;

    if( l==i and i==r )
    {
        level=0;
        tree[node]= val;
        return;
    }

    int mid= (l+r)/2;
    int lChild= 2*node;
    int rChild= 2*node+1;

    update( lChild, l, mid, i, val );
    update( rChild, mid+1, r, i, val );

    level++;

    if( level & 1 )
        tree[node]= tree[lChild] | tree[rChild];
    else
        tree[node]= tree[lChild] ^ tree[rChild];
}

int main()
{
    int n,q;
    scanf("%d %d", &n, &q);

    int lim= 1<<n;

    for(int i=1;i<=lim;i++)
        scanf("%d", &arr[i]);

    build( 1, 1, lim );

    while(q--)
    {
        int p,b;
        scanf("%d %d", &p, &b);
        update( 1, 1, lim, p, b );

        printf("%d\n", tree[1]);
    }
}

