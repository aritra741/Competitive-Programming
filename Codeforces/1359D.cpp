#include<bits/stdc++.h>
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 100007
using namespace std;

vector<int> tree[4*mx], khali(5,0);
int arr[mx];
int n;

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node].push_back(arr[l]);
        tree[node].push_back(arr[l]);
        tree[node].push_back(arr[l]);
        tree[node].push_back(arr[l]);
        tree[node].push_back(arr[l]);
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node].push_back(max( tree[lchild][0], tree[rchild][0] ));
    tree[node].push_back(max( tree[lchild][1], tree[lchild][3]+tree[rchild][1] ));
    tree[node].push_back(max( tree[rchild][2], tree[lchild][2]+tree[rchild][3] ));
    tree[node].push_back(tree[lchild][3]+tree[rchild][3]);
    tree[node].push_back(max( tree[lchild][4], max( tree[rchild][4], tree[lchild][2]+tree[rchild][1] ) ));
}

int daanequery( int node, int l, int r, int i, int j, int x )
{
    if( l>j or r<i )
        return n+1;
    if( l>=i and r<=j and l!=r )
    {
        if( tree[lchild][0]>arr[x] )
            return daanequery( lchild, l, mid, i, j, x );
        if( tree[rchild][0]>arr[x] )
            return daanequery( rchild, mid+1, r, i, j, x );
        return n+1;
    }

    if( l==r )
    {
        if(tree[node][0]>arr[x])
            return l;
        return n+1;
    }

    int q1= daanequery( lchild, l, mid, i, j, x );
    int q2= daanequery( rchild, mid+1, r, i, j, x );

    return min( q1,q2 );
}

vector<int> query( int node, int l, int r, int i, int j )
{
    if(i>j)
        return khali;
    if( l>j or r<i )
        return khali;
    if( l>=i and r<=j )
        return tree[node];

    vector<int> q1= query( lchild, l, mid, i, j );
    vector<int> q2= query( rchild, mid+1, r, i, j );

    vector<int>ret;

    ret.push_back(0);
    ret.push_back(max( q1[1], q1[3]+q2[1] ));
    ret.push_back(max( q2[2], q2[3]+q1[2] ));
    ret.push_back(q1[3]+q2[3]);
    ret.push_back( max( q2[4], max( q1[2]+q2[1], q1[4] ) ) );

//    cout<<l<<" "<<r<<" "<<ret[4]<<endl;

    return ret;
}

int baamequery( int node, int l, int r, int i, int j, int x )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j and l!=r )
    {
        if( tree[rchild][0]>arr[x] )
            return baamequery( rchild, mid+1, r, i, j, x );
        if( tree[lchild][0]>arr[x] )
            return baamequery( lchild, l, mid, i, j, x );
        return 0;
    }

    if( l==r )
    {
        if(tree[node][0]>arr[x])
            return l;
        return 0;
    }

    int q1= baamequery( lchild, l, mid, i, j, x );
    int q2= baamequery( rchild, mid+1, r, i, j, x );

    return max( q1,q2 );
}

int daaneprefix( int node, int l, int r, int i, int j )
{
//    cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<tree[node][1]<<endl;
    if(i>j)
        return 0;
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node][1];

    int q1= daaneprefix( lchild, l, mid, i, j );
    int q2= daaneprefix( rchild, mid+1, r, i, j );

    return q1+q2;
}

int baamesuffix( int node, int l, int r, int i, int j )
{
    if(i>j)
        return 0;
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node][2];

    int q1= baamesuffix( lchild, l, mid, i, j );
    int q2= baamesuffix( rchild, mid+1, r, i, j );

    return q1+q2;
}

int main()
{
    scanf("%d", &n);

    for( int i=1;i<=n;i++ )
        scanf("%d", &arr[i]);

    build( 1, 1, n );

    int ans= 0;

    for( int i=1;i<=n;i++ )
    {
        if(arr[i]<0)
            continue;
        int r= daanequery( 1, 1, n, i, n, i );
        r--;
        int l= baamequery( 1, 1, n, 1, i, i );
        l++;
        vector<int> tot= query( 1, 1, n, l, r );

        ans= max( ans, tot[4]-arr[i] );
    }

    printf("%d\n", ans);

}
