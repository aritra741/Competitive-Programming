#include <bits/stdc++.h>
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int arr[10007];
int ans[10007];
int out[500007];
int tree[40007];
vector<pii> qq[500007];

void update( int node, int l, int r, int i, int j, int x )
{
	if ( l > j or r < i )
		return;
	if (l == r and l == i)
	{
		tree[node] = max(tree[node], x);
		return;
	}

	update( lchild, l, mid, i, j, x );
	update( rchild, mid + 1, r, i, j, x );

	tree[node] = max( tree[lchild], tree[rchild] );
}

int query( int node, int l, int r, int i, int j )
{
	if ( l > j or r < i )
		return 0;
	if ( l >= i and r <= j )
		return tree[node];

	int q1 = query( lchild, l, mid, i, j );
	int q2 = query( rchild, mid + 1, r, i, j );

	return max( q1, q2 );
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);

	for ( int i = 1; i <= n; i++ )
		scanf("%d", &arr[i]);

	for ( int i = 1; i <= q; i++ )
	{
		int l, r;
		scanf("%d %d", &l, &r);

		qq[r].push_back({l, i});
	}

	map<int, int>last;

	for ( int i = 1; i <= n; i++ )
	{
		int a = arr[i];
		for ( int d = 1; d * d <= arr[i]; d++ )
		{
			if (a % d)
				continue;

			int x = d, y = a / d;
	
			if ( last[x] )
			{
				update( 1, 1, n, last[x], last[x], x );
			}

			if(y!=x)
				last[x] = i;

			if ( y != x and last[y] )
			{
				update( 1, 1, n, last[y], last[y], y );
			}

			last[y] = i;
		}

		for ( auto vv : qq[i] )
			out[ vv.ss ] = query( 1, 1, n, vv.ff, i );
	}

	for ( int i = 1; i <= q; i++ )
		printf("%d\n", out[i]);
}