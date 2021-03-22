#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mx 200007
using namespace std;

int inv[mx];
multiset<int>ms[mx];
map<int, int>mp[mx];
int spf[mx];

void sieve()
{
	spf[1] = 1;

	for ( int i = 2; i < mx; i++ )
	{
		if (!spf[i])
		{
			spf[i] = i;
			for ( int j = i * 2; j < mx; j += i )
				if (!spf[j])
					spf[j] = i;
		}
	}
}

int Pow( ll x, ll y )
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


// void init()
// {
// 	inv[1] = 1;
// 	for ( int i = 2; i < mx; i++ ) {
// 		inv[i] = 1LL * (-(mod / i) * inv[mod % i] ) % mod;
// 		inv[i] = inv[i] + mod;
// 	}
// }

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();
	// init();

	int n, q;
	cin >> n >> q;

	ll arr[n + 5];
	ll g = 0;

	for ( int i = 1; i <= n; i++ )
	{
		cin >> arr[i];

		int x = arr[i];
		g = __gcd(g, x * 1LL);

		while (x != 1)
		{
			int y = spf[x];
			int cnt = 0;

			while ((x / y)*y == x)
				x /= y, cnt++;

			mp[i][y] = cnt;
			ms[y].insert(cnt);
		}
	}

	while (q--)
	{
		int i, x;
		cin >> i >> x;

		arr[i] *= x;
		// cout<<" "<<arr[i]<<endl;

		while (x != 1)
		{
			int y = spf[x];
			int cnt = 0;

			while ((x / y)*y == x)
				x /= y, cnt++;

			int ekhon = mp[i][y];
			int ekhonG = 1;
			ll dem= 1;

			if ( ms[y].size() == n )
				ekhonG = Pow(y, *(ms[y].begin())),
				ekhonG = Pow(ekhonG, mod-2);

			if ( ms[y].find(ekhon) != ms[y].end() )
				ms[y].erase(ms[y].find(ekhon));

			mp[i][y] += cnt;
			ms[y].insert(mp[i][y]);

			if (ms[y].size() == n)
			{
				g = (g * ekhonG ) % mod;
				g = (g * Pow(y, *(ms[y].begin()))) % mod;
			}
		}

		cout << g << "\n";
	}
}