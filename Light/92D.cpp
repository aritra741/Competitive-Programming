#include<bits/stdc++.h>
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 100007
#define inf 2e9
using namespace std;

int arr[mx], tree[4*mx];

void update( int node, int l, int r, int i, int x )
{
    if( l>i or r<i )
        return;
    if( l>=i and r<=i )
    {
        tree[node]= x;
        return;
    }

    update( lchild, l, mid, i, x );
    update( rchild, mid+1, r, i, x );

    tree[node]= min( tree[lchild], tree[rchild] );
}

int query( int node, int l, int r, int i, int j, int x )
{
    if( l>j or r<i )
        return -1;
    if( l>=i and r<=j and l!=r )
    {
        if( tree[rchild]<x )
            return query( rchild, mid+1, r, i, j, x );
        return query( lchild, l, mid, i, j, x );
    }

    if(l==r )
    {
        if( tree[node]>=x )
            return -1;
        return l;
    }

    int q1= query( lchild, l, mid, i, j, x );
    int q2= query( rchild, mid+1, r, i, j, x );

    return max(q1,q2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset( tree, 0x3f, sizeof(tree) );

    int n;
    cin>>n;

    for( int i=1;i<=n;i++ )
        cin>> arr[i];

    vector<int>v;

    for( int i=n;i>=1;i-- )
    {
        int ans= -1;

        if(i<n)
            ans= query( 1, 1, n, i+1, n, arr[i] );

        if( ans>1e9 )
            ans= -1;

        if( ans==-1 )
            v.push_back(ans);
        else
            v.push_back(ans-i-1);

        update( 1, 1, n, i, arr[i] );
    }

    reverse( v.begin(), v.end() );

    for( auto x: v )
        cout<<x<<" ";
}
