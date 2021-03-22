#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inv2 500000004
using namespace std;

ll val( ll n )
{
	n %= mod;

	return (((n * (n + 1)) % mod) * inv2) % mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;

	ll ans = 0;

	for ( ll i = 1; i * i <= n; i++ )
	{
		ll y = i;
		ll x = n / y;

		if (y > m)
			break;

		ll l = 1, r = x, now = r;
		ll tot;
		now = n / (y + 1);
		now++;

		if (now <= m)
		{
			x = min(x, m);

			tot = (( val(x) - val(now - 1) ) % mod + mod) % mod;
			tot = (tot * y) % mod;
			ans = ( ans + tot ) % mod;

		}

		if (i == n / i)
			continue;

		y = n / i;
		x = i;

		l = 1, r = x, now = r;
		now = n / (y + 1);
		now++;

		if (now > m)
			continue;
		x = min(x, m);

		tot = (( val(x) - val(now - 1) ) % mod + mod) % mod;
		tot = (tot * y) % mod;

		ans = ( ans + tot ) % mod;
	}

	cout << ((((m % mod) * (n % mod)) % mod - ans ) % mod + mod) % mod << "\n";
}