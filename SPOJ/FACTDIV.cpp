#include <bits/stdc++.h>
#define ll long long
#define mx 1000007
#define mod 1000000007
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
using namespace std;

int ok[mx];
ll sum[mx], ans;
int tot[mx], cont[mx];
ll inv[mx];

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

void sieve()
{
	ok[0] = ok[1] = 1;
	cont[1] = 1;

	for ( int i = 2; i < mx; i++ )
	{
		cont[i] = 1;
		if (!ok[i])
		{
			ok[i] = i;
			for ( int j = i * 2; j < mx; j += i )
				if (!ok[j])
					ok[j] = i;
		}
	}
}

void init()
{
	sieve();
	ans = 1;

	inv[1] = 1;
	for ( int i = 2; i < mx; i++ ) {
		inv[i] = (-(mod / i) * inv[mod % i] ) % mod;
		inv[i] = inv[i] + mod;
	}

	for ( int i = 1; i < mx; i++ )
	{
		int x = i;
		ll now = 1;

		while (ok[x] != 1)
		{
			int spf = ok[x];
			int pp = 0;

			while (x % spf == 0)
				x /= spf, pp++;

			ans = (ans * inv[cont[spf]]) % mod;
			tot[spf] += pp;
			ans = ( ans * (tot[spf] + 1) ) % mod;
			cont[spf] = tot[spf] + 1;
		}

		sum[i] = (sum[i - 1] + ans) % mod;
	}
}

int main()
{
	init();
	int tc;
	scanf("%d", &tc);

	while (tc--)
	{
		int l, r;
		scanf("%d %d", &l, &r);

		printf("%lld\n", (sum[r] - sum[l - 1] + mod) % mod);
	}
}
