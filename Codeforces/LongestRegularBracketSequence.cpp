#include <bits/stdc++.h>
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mx 1000007
#define pii pair<int,int>
using namespace std;

string s;
struct
{
    int open, close;
} tree[4*mx];
int ans,cnt;

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
    ans= max( ans, r-l+1-(tree[node].open+tree[node].close) );
}

pii query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return pii(0,0);
    if( l>=i and r<=j )
        return pii(tree[node].open,tree[node].close);

    pii q1= query( lchild, l, mid, i, j );
    pii q2= query( rchild, mid+1, r, i, j );
    int mn= min( q1.first, q2.second );

    cout<<l<<" "<<r<<" "<<mn*2<<endl;
    return pii(q1.first+q2.first-mn, q1.second+q2.second-mn);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>s;
    int n= s.size();

    build( 1, 1, n );

    if(!ans)
        return cout<<"0 1"<<endl, 0;

    for( int i=1; i<=n-ans+1; i++ )
    {
        pii nd= query( 1, 1, n, i, i+ans-1 );

        if( !(nd.first+nd.second) )
            cnt++;
    }

    cout<<ans<<" "<<cnt<<endl;
}

