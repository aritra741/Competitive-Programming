///Range Sum Query
#include <bits/stdc++.h>
#define MX 100005
using namespace std;

int tree[MX*4];
int arr[MX];

void build(int node, int l, int r)
{
    if(l==r)                        ///Leaf node
    {
        tree[node]=arr[l];
        return;
    }

    int left= build( 2*node, l, (l+r)/2 );
    int right= build( 2*node+1, (l+r)/2+1, r);

    tree[node]= left + right;
}

int getSum(int current, int left, int right, int ql, int qr)    /// qr=query right
{                                                               /// ql=query left
    if(qr<left or ql>right)                                     /// left= starting index of the current node's range
            return 0;                                           /// right= ending index of the current node's range
    if(qr<=right and ql>=left)
        return tree[current];

    int l= getSum( current*2, left, (left+right)/2, ql, qr );
    int r= getSum( current*2+1, (left+right)/2, right, ql, qr );

    return l+r;
}

void update(int current, int l, int r, int idx, int val)        ///Update an index
{
    if(l>r or l>idx or r<idx)
        return;
    if(l==r)
    {
        tree[current]=val;
        return;
    }

    int left= update(current*2, l, (l+r)/2, idx, val);
    int right= update(current*2+1, (l+r)/2 + 1, r, idx, val);

    tree[current]= left + right; /// tree[current] will be updated if either if its child nodes has been updated
}

void update(int current, int l, int r, int ql, int qr, int val)        ///Update in a range
{
    if(l>r or l>qr or r<ql)
        return;
    if(l==r)
    {
        tree[current]=val;
        return;
    }

    int left= update(current*2, l, (l+r)/2, ql, qr val);
    int right= update(current*2+1, (l+r)/2 + 1, r, ql, qr, val);

    tree[current]= left + right; /// tree[current] will be updated if either if its child nodes has been updated
}

int main()
{

}
