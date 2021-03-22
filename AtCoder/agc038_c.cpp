#include <bits/stdc++.h>
#define ll long long
#define mx 1000007
#define mod 998244353
using namespace std;

ll cnt[mx];
ll inv[mx];
ll tot[mx];

void init()
{
	inv[1] = 1;
	for ( ll i = 2; i < mx; i++ ) {
		inv[i] = (-(mod / i) * inv[mod % i] ) % mod;
		inv[i] = inv[i] + mod;
	}
}

int main()
{
	init();

	int n;
	scanf("%d", &n);

	int arr[n + 5];
	ll ans = 0;

	for ( int i = 0; i < n; i++ )
		scanf("%d", &arr[i]), cnt[arr[i]]++;

	for ( int i = mx - 1; i >= 1; i-- )
	{
		ll sum = (cnt[i] * i) % mod;
		ll baad = (cnt[i] * i * i) % mod;

		for ( ll j = i + i; j < mx; j += i )
		{
			sum += (cnt[j] * j) % mod, baad += (cnt[j] * j * j) % mod;
			baad %= mod;
			baad += tot[j];
			sum %= mod;
			baad %= mod;
		}

		sum = (sum * sum) % mod;
		sum = ((sum - baad) % mod + mod) % mod;
		tot[i] = sum;
		sum = (sum * inv[2]) % mod;
		sum = (sum * inv[i]) % mod;
		ans = (ans + sum) % mod;
	}

	printf("%lld\n", ans);

	for ( int i = 0; i < mx; i++ )
		cnt[i] = 0, tot[i] = 0;
}