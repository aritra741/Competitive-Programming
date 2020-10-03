#include <bits/stdc++.h>
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
#define mx 200007
using namespace std;

int tree[4*mx];

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
	
	return max(q1,q2);
}

void clean( int node, int l, int r )
{
	if( l==r )
	{
		tree[node]= 0;
		return;
	}

	clean( lchild, l, mid );
	clean( rchild, mid+1, r );
	
	tree[node]= 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,k;
		cin>>n>>k;

		int arr[n+5];

		for( int i=1;i<=n;i++ )
			cin>>arr[i];

		sort( arr+1, arr+n+1 );

		int p;

		for( int i=1;i<=n;i++ )
			cin>>p;

		std::vector<int> v;
		int ans= 0;

		for( int i=n;i>=1;i-- )
		{
			int pos= upper_bound( arr+i+1, arr+n+1, arr[i]+k )-arr;
			int tmp= pos-i;
			if( pos<=n )
				tmp+= query( 1, 1, n, pos, n  );
			ans= max( ans, tmp );
			update( 1, 1, n, i, pos-i );
		}

		cout<< ans <<"\n";

		clean( 1, 1, n );  
	}
}