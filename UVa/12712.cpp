#include <bits/stdc++.h>
#define ll long long
#define mx 10007
#define mod 10000000000007LL
using namespace std;

ll f[mx], npr[mx][mx];

void init()
{
	f[0] = f[1] = 1;

	for ( int i = 2; i < mx; i++ )
		f[i] = (f[i - 1] * i) % mod;

	for ( int i = 0; i < mx; i++ )
	{
		npr[i][0] = 1;

		for ( int j = 1; j <= i; j++ )
			npr[i][j] = (npr[i - 1][j] + npr[i - 1][j - 1]) % mod;
	}

	for ( int i = 0; i < mx; i++ )
		for ( int j = 0; j <= i; j++ )
			npr[i][j] = ((__int128)npr[i][j]*f[j])%mod;

	for ( int i = 0; i < mx; i++ )
		for ( int j = 1; j <= i; j++ )
			npr[i][j] = (npr[i][j] + npr[i][j - 1]) % mod;
}

int main()
{
	init();

	int tc;
	scanf("%d", &tc);

	for ( int t = 1; t <= tc; t++ )
	{
		int l, m, n;
		scanf("%d %d %d", &l, &m, &n);

		ll ans = ((npr[l * l][n] - npr[l * l][m - 1] ) % mod + mod) % mod;

		printf("Case %d: %lld\n", t, ans);
	}
}