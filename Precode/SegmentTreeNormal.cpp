#include <bits/stdc++.h>
#define MX 500007
using namespace std;

int arr[MX];
struct{
    int mx;
}tree[MX*4] ;

void build( int node, int l, int r )
{
    if(l==r)
    {
        tree[node].sum=arr[l];
        return;
    }

    int lChild= 2*node;
    int rChild= 2*node+1;
    int mid=(left+right)/2;
    build( lChild, l, mid );
    build( rChild, mid+1, r );

    tree[node].sum=lChild.sum+rChild.sum;
}

void update( int node, int l, int r, int left, int right, int x )
{
    if(l>right or r<left)
        return;
    else if(l<=left and r>=right)
    {
        tree[node].sum+=(right-left+1)*x;
        tree[node].lazy+=x;
        return;
    }

    int lChild= 2*node;
    int rChild= 2*node+1;
    int mid=(left+right)/2;

    update( lChild, l, r, left, mid, x );
    update( rChild, l, r, mid+1, r, x );

    tree[node].sum= tree[lChild].sum+tree[rChild].sum+ (right-left+1)*tree[node].lazy;

}

int query( int node, int l, int r, int left, int right, int carry=0 )
{
    if(left>r or right<l)
        return 0;
    if(left>=l and right<=r)
        return tree[node].sum+carry*(right-left+1);

    int lChild= 2*node;
    int rChild= 2*node+1;
    int mid=(left+right)/2;

    int q1= query( lChild, l, r, left, mid, carry+tree[node].lazy );
    int q1= query( rChild, l, r, mid+1, right, carry+tree[node].lazy );

    return p1+p2;

}

int main()
{

}
