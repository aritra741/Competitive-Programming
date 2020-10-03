#include <bits/stdc++.h>
#define mx 300007
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
using namespace std;

int tree[4*mx][2], arr[mx];
int dp[mx];
bool vis[mx];

void build( int node, int l, int r )
{
	if( l==r )
	{
		tree[node][0]= tree[node][1]= arr[l];
		return;
	}

	build( lchild, l, mid );
	build( rchild, mid+1, r );

	tree[node][0]= min( tree[lchild][0], tree[rchild][0] );
	tree[node][1]= max( tree[lchild][1], tree[rchild][1] );
}

int querymx( int node, int l, int r, int i, int j, int x )
{
	if( l>j or r<i )
		return 1e9;

	if( l==r )
	{
		if( arr[l]>=x )
			return l;
		return 1e9;
	}

	if( l>=i and r<=j )
	{
		if( tree[lchild][1]>=x )
			return querymx( lchild, l, mid, i, j, x );
		if( tree[rchild][1]>=x )
			return querymx( rchild, mid+1, r, i, j, x );
		return 1e9;
	}

	int q1= querymx( lchild, l, mid, i, j, x );
	int q2= querymx( rchild, mid+1, r, i, j, x );

	return min( q1,q2 );
}

int querymn( int node, int l, int r, int i, int j, int x )
{
	if( l>j or r<i )
		return 1e9;
	if( l==r )
	{
		if( arr[l]<=x )
			return l;
		return 1e9;
	}

	if( l>=i and r<=j )
	{
		if( tree[lchild][0]<=x )
			return querymn( lchild, l, mid, i, j, x );
		if( tree[rchild][0]<=x )
			return querymn( rchild, mid+1, r, i, j, x );
		return 1e9;
	}

	int q1= querymn( lchild, l, mid, i, j, x );
	int q2= querymn( rchild, mid+1, r, i, j, x );

	return min( q1,q2 );
}

int querymxagey( int node, int l, int r, int i, int j, int x )
{
	if( l>j or r<i )
		return 0;

	if( l==r )
	{
		if( arr[l]>=x )
			return l;
		return 0;
	}

	if( l>=i and r<=j )
	{
		if( tree[rchild][1]>=x )
			return querymxagey( rchild, mid+1, r, i, j, x );
		if( tree[lchild][1]>=x )
			return querymxagey( lchild, l, mid, i, j, x );
		return 0;
	}

	int q1= querymxagey( lchild, l, mid, i, j, x );
	int q2= querymxagey( rchild, mid+1, r, i, j, x );

	return max( q1,q2 );
}

int querymnagey( int node, int l, int r, int i, int j, int x )
{
	if( l>j or r<i )
		return 0;
	if( l==r )
	{
		if( arr[l]<=x )
			return l;
		return 0;
	}

	if( l>=i and r<=j )
	{
		if( tree[rchild][0]<=x )
			return querymnagey( rchild, mid+1, r, i, j, x );
		if( tree[lchild][0]<=x )
			return querymnagey( lchild, l, mid, i, j, x );
		return 0;
	}

	int q1= querymnagey( lchild, l, mid, i, j, x );
	int q2= querymnagey( rchild, mid+1, r, i, j, x );

	return max( q1,q2 );
}


int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;

	for( int i=1;i<=n;i++ )
		cin>>arr[i];

	build( 1, 1, n );

	for( int i=1;i<n;i++ )
		dp[i]= n+1;

	for( int i=n;i>=1;i-- )
	{
		int q1= querymn( 1, 1, n, i+1, n, arr[i] );
		int q2= querymx( 1, 1, n, i+1, n, arr[i] );
		
		if(q1<=n)
			dp[i]= min( dp[i], 1+dp[q1] );
		if(q2<=n)
			dp[i]= min( dp[i], 1+dp[q2] );

		if( i>1 )
		{
			int q3= querymnagey( 1, 1, n, 1, i-1, arr[i] );
			int q4= querymxagey( 1, 1, n, 1, i-1, arr[i] );
			
			if(q3>=1)
				dp[q3]= min( dp[q3], 1+dp[i] );
			if(q4>=1)
				dp[q4]= min( dp[q4], 1+dp[i] );
		}
	}

	cout<< dp[1] <<"\n";
}
