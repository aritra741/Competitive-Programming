#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mp[10000007], cnt[10000007];
int ok[10000007];
int prime[10000007];
int cc = 0;

void sieve()
{
	ok[0] = ok[1] = 1;

	for ( ll i = 2; i < 10000007; i ++ )
	{
		if (!ok[i])
		{
			prime[cc++] = i;

			for ( ll j = i * 2; j < 10000007; j += i )
				if ( !ok[j] )
					ok[j] = i;
		}
	}
}

bool isPrime(int x)
{
	return (ok[x] == 0);
}

int sqt( int n )
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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int a[n + 5], b[m + 5];

	for ( int j = 0; j < n; j++ )
	{
		cin >> a[j];
		int x = a[j];

		for ( int i = 0; i < cc and 1LL*prime[i]*prime[i]*prime[i] <= x; i++ )
		{
			int y = prime[i];

			if ( x % y )
				continue;

			while (x % prime[i] == 0)
				x /= prime[i], mp[prime[i]]++;
		}

		int y = x;

		if ( isPrime(y) )
		{
			mp[y]++;
		}

		else if ( sqt(y)*sqt(y) == y and isPrime( sqt(y) ) )
		{
			mp[sqt(y)] += 2;
		}
		else if (y > 1)
		{
			int yy = y;
			y = ok[y];
			mp[y]++;
			y = yy / y;
			mp[y]++;
		}
	}

	for ( int j = 0; j < m; j++ )
	{
		cin >> b[j];
		int x = b[j];

		for ( int i = 0; i < cc and prime[i]*prime[i]*prime[i] <= x; i++ )
		{
			int y = prime[i];

			if ( x % y )
				continue;
			while (x % prime[i] == 0)
			{
				x /= prime[i];

				if (mp[prime[i]])
					b[j] /= prime[i], mp[prime[i]]--, cnt[prime[i]]++;
			}
		}

		int y = x;

		if ( isPrime(y) )
		{
			if (mp[y])
				mp[y]--, cnt[y]++, b[j] /= y;
		}

		else if ( sqt(y)*sqt(y) == y and isPrime( sqt(y) ) )
		{
			if (mp[sqt(y)])
				mp[sqt(y)]--, cnt[sqt(y)]++, b[j] /= sqt(y);
			if (mp[sqt(y)])
				mp[sqt(y)]--, cnt[sqt(y)]++, b[j] /= sqt(y);
		}

		else if (y > 1)
		{
			int yy = y;
			y = ok[y];
			if (mp[y])
				mp[y]--, cnt[y]++, b[j] /= y;
			y = yy / y;
			if (mp[y])
				mp[y]--, cnt[y]++, b[j] /= y;
		}
	}

	for ( int j = 0; j < n; j++ )
	{
		int x = a[j];

		for ( int i = 0; i < cc and prime[i]*prime[i]*prime[i] <= x; i++ )
		{
			int y = prime[i];

			if ( x % y )
				continue;
			while (x % prime[i] == 0)
			{
				x /= prime[i];

				if (cnt[prime[i]])
					a[j] /= prime[i], cnt[prime[i]]--;
			}
		}

		int y = x;

		if ( isPrime(y) )
		{
			if (cnt[y])
				a[j]/= y, cnt[y]--;
		}

		else if ( sqt(y)*sqt(y) == y and isPrime( sqt(y) ) )
		{
			if (cnt[sqt(y)])
				a[j]/= sqt(y), cnt[sqt(y)]--;
			if (cnt[sqt(y)])
				a[j]/= sqt(y), cnt[sqt(y)]--;
		}

		else if (y > 1)
		{
			int yy = y;
			y = ok[y];
			if (cnt[y])
				a[j]/= y, cnt[y]--;
			y = yy / y;
			if (cnt[y])
				a[j]/= y, cnt[y]--;
		}
	}

	cout << n << " " << m << "\n";

	for ( int i = 0; i < n; i++ )
		cout << a[i] << " ";
	cout << "\n";
	for ( int i = 0; i < m; i++ )
		cout << b[i] << " ";

}