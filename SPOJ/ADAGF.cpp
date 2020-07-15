#include<bits/stdc++.h>
#define ll long long
#define mx 300007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

int tree[4*mx], arr[mx];
int n;

void build( int node, int l, int r )
{
    if(l==r)
    {
        tree[node]= arr[l];
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node]= __gcd( tree[lchild], tree[rchild] );
}

int minquerypore( int node, int l, int r, int i, int j, int k )
{
    if( l>j or r<i )
        return n+1;
    if( l>=i and r<=j and l!=r )
    {
        if( tree[lchild]%k )
            return minquerypore( lchild, l, mid, i, j, k );
        return minquerypore( rchild, mid+1, r, i, j, k );
    }
    if( l==r )
    {
        if( tree[node]%k )
            return l;
        return n+1;
    }

    int q1= minquerypore( lchild, l, mid, i, j, k );
    int q2= minquerypore( rchild, mid+1, r, i, j, k );

    return min( q1,q2 );
}

int minqueryagey( int node, int l, int r, int i, int j, int k )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j and l!=r )
    {
        if( tree[rchild]%k or tree[rchild]==k )
            return minqueryagey( rchild, mid+1, r, i, j, k );
        return minqueryagey( lchild, l, mid, i, j, k );
    }
    if( l==r )
    {
        if( tree[node]%k or tree[rchild]==k )
            return l;
        return 0;
    }

    int q1= minqueryagey( lchild, l, mid, i, j, k );
    int q2= minqueryagey( rchild, mid+1, r, i, j, k );

    return max( q1,q2 );
}

ll jogfol(ll x)
{
    return (x*(x+1))/2;
}
int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1;t<=tc;t++ )
    {
        ll ans= 0;
        scanf("%d", &n);

        for( int i=1;i<=n;i++ )
            scanf("%d", &arr[i]);

        build( 1, 1, n );

        for( ll i=1;i<=n;i++ )
        {
            ll pore= minquerypore( 1, 1, n, i+1, n, arr[i] );
            ll agey= minqueryagey( 1, 1, n, 1, i-1, arr[i] );

//            ll biyog= jogfol(pore-i)-1+jogfol(i-agey)-1+1+i-agey+pore-i-1;
//
//            ans-= biyog*abs(arr[i]);
//
            ll jog= (i*(n-i+1))*arr[i];
//
//            ans+= jog*abs(arr[i]);
//
//            cout<<ans<<endl;


//            ll porergula= jogfol(pore-i-1)*(i-agey)*arr[i];
//            ll agergula= jogfol(i-agey)*(pore-i)*arr[i];

//            ll biyog= porergula+agergula;

            ans+= jog;
//            ans-= biyog;

//            cout<<i<<" "<<arr[i]<<" "<<i-agey<<" "<<pore-i<<endl;
        }

        printf("Case %d: %lld\n", t, ans);

        memset( tree, 0, sizeof(tree) );
    }
}
/*
1
4
2 2 5 2
*/
