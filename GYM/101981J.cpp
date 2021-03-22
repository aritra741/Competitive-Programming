#include <bits/stdc++.h>
#define mx 1000007
#define ll long long
using namespace std;

int ok[mx];
int prime[mx];
int cnt = 0;

void sieve()
{
	ok[0] = ok[1] = 1;

	for ( ll i = 2; i < mx; i ++ )
	{
		if (!ok[i])
		{
			prime[cnt++] = i;

			for ( ll j = i * 2; j < mx; j += i )
				if ( !ok[j] )
					ok[j] = i;
		}
	}
}
int mp[1000007];

bool isPrime(int x)
{
	return (ok[x] == 0);
}

int sq( int n )
{
	int s = sqrt(n);

	if ( (s - 1) * (s - 1) == n )
		return s - 1;
	if ( (s + 1) * (s + 1) == n )
		return s + 1;
	return s;
}

int main()
{
	sieve();

	int n;
	scanf("%d", &n);

	int arr[n + 5];

	for ( int i = 1; i <= n; i++ )
		scanf("%d", &arr[i]);

	ll ans = 0;

	for ( ll j = n; j >= 1; j-- )
	{
		int x = arr[j];

		for ( int i = 0; i < cnt and prime[i]*prime[i]*prime[i] <= x; i++ )
		{
			int y = prime[i];

			if ( x % y )
				continue;
			if (mp[y])
				ans += (mp[y] - j) * j;
			else
				ans += (n - j + 1) * j;

			while (x % prime[i] == 0)
				x /= prime[i];

			mp[y] = j;
		}

		int y = x;

		if ( isPrime(y) )
		{
			if (mp[y])
				ans += (mp[y] - j) * j;
			else
				ans += (n - j + 1) * j;

			mp[y] = j;
		}

		else if ( sq(y)*sq(y) == y and isPrime( sq(y) ) )
		{
			y = sq(y);

			if (mp[y])
				ans += (mp[y] - j) * j;
			else
				ans += (n - j + 1) * j;

			mp[y] = j;
		}
		else if (y > 1)
		{
			int yy = y;
			y = ok[y];

			if (mp[y])
				ans += (mp[y] - j) * j;
			else
				ans += (n - j + 1) * j;

			mp[y] = j;
			y = yy / y;

			if(y==yy)
				continue;

			if (mp[y])
				ans += (mp[y] - j) * j;
			else
				ans += (n - j + 1) * j;

			mp[y] = j;
		}

	}

	printf("%lld\n", ans);
}