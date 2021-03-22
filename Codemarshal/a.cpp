#include <bits/stdc++.h>
#define mx 5000007
#define mod 100000007
#define ll long long
using namespace std;

int ok[mx];
ll pw[mx][32];
int pr[mx];
int cnt;

ll ans[mx];
ll now = 1;

ll Pow( ll x, ll y )
{
	ll res = 1;

	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}

	return res;
}

void update( int node, int l, int r, ll i, ll x )
{
	if(l>i or r<i)
		return;
	if(l>=i and r<=i)
	{
		tree[node]= ge;
		return;
	}

	update( lchild, l, mid, i, x );
	update( rchild, mid+1, r, i, x );

	tree[node]= ( tree[lchild]*tree[rchild] )%mod;
}

void sieve()
{
	ok[0] = ok[1] = 1;

	for ( int i = 2; i < mx; i++ )
	{
		if (!ok[i])
		{
			pr[cnt++]= i;
			ok[i] = i;

			ll x = i;
			ll y = 0;

			for (;;)
			{
				if ( x <= mx )
					pw[i][y++] = x, x *= i;
				else
					break;
			}

			for ( int j = i * 2; j < mx; j += i )
				if (!ok[j])
					ok[j] = i;
		}
	}
}

int main()
{
	sieve();
	int n;

	while (scanf("%d", &n)==1 and n)
	{
		ll ans = 1;

		for ( int i = 2; i <= n; i++ )
		{
			ll tot = 0;
			if (ok[i] == i)
			{
				ll x = i;
				ll cc = 0;
				ll sum = 0;

				while (x <= n)
				{
					ll y = x + i;
					ll z = pw[i][0];
					int f = 0;

					if (y > n)
						y = n, f = 1;

					ll baki = y - x + f;

					int cn = 0;

					for (;;)
					{
						if (!z or z > x)
							break;
						cc = x / z;
						ll now = (cc * baki) % mod;
						// cout << x << " " <<cc<<" "<< z << " " << now << endl;
						sum = (sum + now) % mod;
						z = pw[i][++cn];
					}

					x += i;
				}

				// if (x + i > n)
				// {
				// 	ll baki = n - x + 1;
				// 	ll now = (pre[cc] * baki) % mod;
				// 	sum = (sum + now) % mod;
				// }

				cout<<i<<" "<<sum+1<<endl;
				sum = (sum + 1) % mod;
				ans = (ans * sum) % mod;
			}
		}

		printf("%lld\n", ans);
	}

}