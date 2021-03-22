#include <bits/stdc++.h>
#define ll long long
#define mx 1000007
#define mod 10000007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

int ok[mx];
ll sum[mx], ans;
int tot[mx], cont[mx];
int cnt= 0;
ll tree[4*mx];

ll val(ll n)
{
	return ((n*(n+1))/2)%mod;
}

void update( int node, int l, int r, ll i, ll x )
{
	if(l>i or r<i)
		return;
	if(l>=i and r<=i)
	{
		tree[node]= val(x);
		return;
	}

	update( lchild, l, mid, i, x );
	update( rchild, mid+1, r, i, x );

	tree[node]= ( tree[lchild]*tree[rchild] )%mod;
}

ll Pow( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res;
}

void sieve()
{
	ok[0]= ok[1]= 1;
    cont[1]= 1;
    tree[1]= 1;

	for( int i=2;i<mx;i++ )
	{
		tree[i]= 1;
	    cont[i]= 1;
		if(!ok[i])
		{
			cnt++;
		    ok[i]= i;
			for( int j=i*2;j<mx;j+=i )
				if(!ok[j])
					ok[j]= i;
		}
	}

	for( int i=1;i<4*mx;i++ )
		tree[i]= 1;
}

void init()
{
	sieve();
	ans= 1;

	for( int i=1;i<mx;i++ )
	{
		int x= i;
		ll now= 1;

		while(ok[x]!=1)
		{
			int spf= ok[x];
			int pp= 0;

			while(x%spf==0)
				x/= spf, pp++;

            tot[spf]+= pp;
            update( 1, 1, mx-1, spf, tot[spf]+1 );

			cont[spf]= val(tot[spf]+1);
		}

		sum[i]= tree[1];
	}
}

int main()
{
	init();
	int n;

	while(scanf("%d", &n)==1 and n)
	{
		printf("%lld\n", sum[n]);
	}
}
