#include <bits/stdc++.h>
#define MX 100007
#define ll long long
using namespace std;

bool prime[MX];
int arr[MX];
int tree[3*MX];

void sieve(void)
{
    prime[0]=prime[1]=1;

    for(ll i=2;i<MX;i++)
    {
        if(!prime[i])
        {
            for(ll j=i*i;j<MX;j+=i)
                prime[j]=1;
        }
    }
}

void build( int node, int l, int r )
{
    if(l==r)
    {
        if(prime[ arr[l] ]==0)
            tree[node]=1;
        else tree[node]=0;
        return;
    }

    int lChild=2*node;
    int rChild=2*node+1;
    int mid=(l+r)/2;

    build( lChild, l, mid );
    build( rChild, mid+1, r );

    tree[node]=tree[lChild]+tree[rChild];

}

void update(int node, int l, int r, int i, int j, int val)
{
    if(l>j or r<i)
        return;
    if(l>=i and r<=j)
    {
        if( prime[ val ]==0 )
            tree[node]=1;
        else
            tree[node]=0;
        return;
    }

    int lChild=2*node;
    int rChild=2*node+1;
    int mid=(l+r)/2;

    update( lChild, l, mid, i, j, val );
    update( rChild, mid+1, r, i, j, val );

    tree[node]= tree[lChild]+tree[rChild];

}

int query( int node, int l, int r, int i, int j )
{
    if(l>j or r<i)
        return 0;
    if(l>=i and r<=j)
        return tree[node];

    int lChild=2*node;
    int rChild=2*node+1;
    int mid=(l+r)/2;

    int q1= query( lChild, l, mid, i, j );
    int q2= query( rChild, mid+1, r, i, j );

    return q1+q2;
}

int main()
{
    sieve();
    int n,q;
    scanf("%d %d", &n, &q);

    for(int i=1;i<=n;i++)
        scanf("%d", &arr[i]);

    build(1, 1, n);

    while(q--)
    {
        int type;
        scanf("%d", &type);

        if(type==1)
        {
            int i,j;
            scanf("%d %d", &i, &j);
            int ans= query(1, 1, n, i, j);
            printf("%d\n", ans);
        }

        else
        {
            int x,y;
            scanf("%d %d", &x, &y);
            update(1, 1, n, x, x, y);
        }
    }

}
