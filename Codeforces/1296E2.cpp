#include<bits/stdc++.h>
#define mx 200007
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
using namespace std;

int arr[mx];
int tree[4*mx];

void update( int node, int l, int r, int i, int x )
{
    if(l>i or r<i)
        return;

    if( l>=i and r<=i )
    {
        tree[node]= max( tree[node], x );
        return;
    }

    update( lchild, l, mid, i, x );
    update( rchild, mid+1, r, i, x );

    tree[node]= max( tree[lchild], tree[rchild] );
}

int query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node];

    int q1= query( lchild, l, mid, i, j );
    int q2= query( rchild, mid+1, r, i, j );

    return max( q1, q2 );
}

int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int ans= 0;

    for( int i=0;i<s.size();i++ )
    {
        int x= s[i]-'a'+1;
        int val= query( 1, 1, 27, x+1, 27 );

        arr[i]= val+1;
        ans= max( ans, val+1 );

        update( 1, 1, 27, x, val+1 );
    }

    cout<<ans<<endl;

    for( int i=0;i<n;i++ )
        cout<< arr[i] <<" ";
}
