#include <bits/stdc++.h>
#define mx 5007
#define ll long long
#define lim 1000000000000001
using namespace std;

bool arr[mx];
std::vector<int> v;

void sieve()
{
	for ( int i = 2; i < mx; i++ )
	{
		if (!arr[i])
		{
			v.push_back(i);

			for ( int j = i * 2; j < mx; j += i )
				arr[j] = 1;
		}
	}
}

int main()
{
	sieve();

	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	for ( int t = 1;; t++ )
	{
		int x;
		cin >> x;

		if (!x)
			break;

		std::vector<int> pp;

		for ( auto y : v )
		{
			while (x % y == 0)
				pp.push_back(y - 1), x /= y;
		}

		if (x > 1)
			pp.push_back(x - 1);

		ll ans = 1;

		int idx = 0;

		sort( pp.begin(), pp.end(), greater<int>() );

		bool f = 1;

		if (pp.size() > 13)
			f = 0;
		else
			for ( auto y : pp )
			{
				ll tmp = v[idx];

				for ( int i = 1; i < y; i++ )
				{
					tmp *= v[idx];

					if (tmp >= lim)
					{
						f = 0;
						break;
					}
				}

				if (!f or (long double)tmp * (long double)ans >= (long double)lim)
				{
					ans = -1;
					break;
				}

				// cout<<v[idx]<<" "<<tmp<<endl;
				ans *= tmp;
				idx++;
			}

		cout << "Case " << t << ": ";

		if (ans == -1 or !f or ans>=lim)
			cout << "Impossible\n";
		else
			cout << ans << "\n";
	}
}