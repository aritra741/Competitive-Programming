#include <bits/stdc++.h>
#define mx 100007
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

int tree[mx*4], arr[mx];
vector<pii> v;

void build( int node, int l, int r )
{
    if( l==r )
    {
        tree[node]= arr[l];
      //  cout<<l<<" "<<r<<" "<<tree[node]<<endl;
        return;
    }

    build( lchild, l, mid );
    build( rchild, mid+1, r );

    tree[node]= __gcd( tree[lchild], tree[rchild] );
     //cout<<l<<" "<<r<<" "<<tree[node]<<endl;
}

int query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0;
    if( l>=i and r<=j )
        return tree[node];

    int q1= query( lchild, l, mid, i, j );
    int q2= query( rchild, mid+1, r, i, j );

    return __gcd( q1,q2 );
}

//bool operator < ( pii a, pii b )
//{
//    if( a.f==b.f )
//        return a.s<b.s;
//    return a.f<b.f;
//}

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=1;i<=n;i++ )
    {
        scanf("%d", &arr[i]);

        v.push_back( pii( arr[i], i+1 ) );
    }

    sort( v.begin(), v.end() );

    build( 1, 1, n );

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int i,j;
        scanf("%d %d", &i, &j);

        int qq= query( 1, 1, n, i, j );
        cout<<i<<" "<<j<<""<<qq<<endl;
        int beche_jaabe= upper_bound( v.begin(), v.end(),  pii(qq,j) )-lower_bound( v.begin(), v.end(),  pii(qq,i) );
        cout<<"bah "<<beche_jaabe<<endl;
        printf("%d\n", j-i+1-beche_jaabe );
    }
}
