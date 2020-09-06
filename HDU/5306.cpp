#include <cstdio>
#include <math.h>
#include <algorithm>
#define ll long long
#define lchild 2*node
#define rchild lchild+1
#define mid (l+r)/2
#define N 1000007
using namespace std;

struct tt
{
	int mx, mx_2, freq, lazy;
	ll sum;
}tree[N*4];

int arr[N];

void push(int node,int l,int r)
{
	if(tree[node].lazy==-1)
		return;
	if(tree[node].lazy>=tree[node].mx)
	{
		tree[node].lazy= -1;
		return;
	}
	if(tree[node].lazy<tree[node].mx)
	{
		tree[node].sum-= 1LL*tree[node].freq*tree[node].mx;
		tree[node].mx= tree[node].lazy;
		tree[node].sum+= 1LL*tree[node].freq*tree[node].mx;
	}

	if(l!=r)
	{
		if(tree[lchild].lazy>-1)
			tree[lchild].lazy= min( tree[lchild].lazy, tree[node].lazy );
		else
			tree[lchild].lazy= tree[node].lazy;
		if(tree[rchild].lazy>-1)
			tree[rchild].lazy= min( tree[rchild].lazy, tree[node].lazy );
		else
			tree[rchild].lazy= tree[node].lazy;
	}

	tree[node].lazy= -1;
}
void combine(int node, int l, int r)
{
	tree[node].sum= tree[lchild].sum+tree[rchild].sum;
	tree[node].mx= max( tree[lchild].mx, tree[rchild].mx );

	if( tree[lchild].mx>tree[rchild].mx )
		tree[node].mx_2= max( tree[rchild].mx,tree[lchild].mx_2 );
	else if( tree[lchild].mx<tree[rchild].mx )
		tree[node].mx_2= max( tree[lchild].mx,tree[rchild].mx_2 );
	else
		tree[node].mx_2= max( tree[lchild].mx_2, tree[rchild].mx_2 );

	if(tree[lchild].mx==tree[rchild].mx)
		tree[node].freq= tree[lchild].freq+tree[rchild].freq;
	else if(tree[lchild].mx>tree[rchild].mx)
		tree[node].freq= tree[lchild].freq;
	else
		tree[node].freq= tree[rchild].freq;
}

void build( int node, int l, int r )
{
	tree[node].lazy= -1;

	if( l==r )
	{
		tree[node].sum= arr[l];
		tree[node].freq= 1;
		tree[node].mx= arr[l];
		tree[node].mx_2= -1;
		return;
	}

	build( lchild, l, mid );
	build( rchild, mid+1, r );

	combine(node,l,r);
}

void update( int node, int l, int r, int i, int j, int x )
{
	push(node,l,r);
	if(l>j || r<i || tree[node].mx<=x)
		return;
	if(l>=i && r<=j)
	{
		if(x>tree[node].mx_2)
		{
			tree[node].lazy= x;
			push(node,l,r);
			return;
		}
	}

	update( lchild, l, mid, i, j, x );
	update( rchild, mid+1, r, i, j, x );

	combine(node, l, r);
}

int querymx( int node, int l, int r, int i, int j )
{
	push(node,l,r);
	if(l>j || r<i)
		return 0;
	if(l>=i && r<=j)
		return tree[node].mx;

	int q1= querymx( lchild, l, mid, i, j );
	int q2= querymx( rchild, mid+1, r, i, j );

	return max( q1,q2 ); 
}

ll querysum( int node, int l, int r, int i, int j )
{
	push(node,l,r);
	if(l>j || r<i)
		return 0;
	if(l>=i && r<=j)
		return tree[node].sum;

	ll q1= querysum( lchild, l, mid, i, j );
	ll q2= querysum( rchild, mid+1, r, i, j );

	return q1+q2; 
}


int main()
{
	int tc;
	scanf("%d", &tc);

	while(tc--)
	{
		int n,m;
		scanf("%d %d", &n, &m);

		for( int i=1;i<=n;i++ )
			scanf("%d", &arr[i]);

		build(1,1,n);

		while(m--)
		{
			int tp,x,y;
			scanf("%d %d %d", &tp, &x, &y);

			if(tp==0)
			{
				int p;
				scanf("%d", &p);

				update( 1, 1, n, x, y, p );
			}
			else if(tp==1)
			{
				int ans= querymx( 1, 1, n, x, y );
				printf("%d\n", ans);
			}
			else
			{
				ll ans= querysum( 1, 1, n, x, y );
				printf("%lld\n", ans);
			}

		}
	}
}