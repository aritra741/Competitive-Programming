#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
#define mx 1000007
using namespace std;

int arr[mx], pref[mx];
map<int,int>last;
int tree[4*mx];
int val;
int ans[mx];
std::vector<pii> v[mx];

void update( int node, int l, int r, int i, int x )
{
	if(l>i or r<i)
		return;
	if(l>=i and r<=i)
	{
		tree[node]= x;
		return;
	}

	update( lchild, l, mid, i, x );
	update( rchild, mid+1, r, i, x );

	tree[node]= tree[lchild]^tree[rchild];
}

int query( int node, int l, int r, int i, int j )
{
	if( l>j or r<i )
		return 0;
	if( l>=i and r<=j )
		return tree[node];

	int q1= query( lchild, l, mid, i, j );
	int q2= query( rchild, mid+1, r, i, j );

	return q1^q2;
}

int main()
{
	int n;
	scanf("%d", &n);

	for ( int i = 1; i <= n; i++ )
		scanf("%d", &arr[i]), pref[i]= arr[i]^pref[i-1];

	int q;
	scanf("%d", &q);

	for ( int i = 1; i <= q; i++ )
	{
		int l, r;
		scanf("%d %d", &l, &r);

		v[r].push_back({l,i});
	}

	for( int i=1;i<=n;i++ )
	{
		if( last[arr[i]] )
			update( 1, 1, n, last[arr[i]], 0 );

		last[arr[i]]= i;
		update( 1, 1, n, i, arr[i] );

		for( auto x: v[i] )
			ans[x.ss]= pref[i]^query( 1, 1, n, x.ff, i )^pref[x.ff-1];
	}

	for ( int i = 1; i <= q; i++ )
		printf("%d\n", ans[i]);
}