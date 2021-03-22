#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll Pow( ll x , ll y )
{
	ll res = 1;

	while (y > 0)
	{
		if (y & 1)
			res = (res * x);
		if (y > 1)
			x = (x * x);
		y >>= 1;
	}

	return res;
}

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		ll p, q;
		cin >> p >> q;

		if ( p > q and p % q )
		{
			cout << p << "\n";
			continue;
		}

		if (q > p)
		{
			std::vector<ll> v;

			for ( ll x = 1; x * x <= p; x++ )
			{
				if ( p % x == 0 )
				{
					if ( x % q )
						v.push_back(x);
					if ( (p / x) % q )
						v.push_back(p / x);
				}
			}

			sort( v.begin(), v.end() );

			cout << v.back() << "\n";
		}
		else
		{
			map<ll, ll>mp;
			ll g = q;

			for ( ll x = 2; x * x <= q; x++ )
			{
				if ( q % x == 0 )
				{
					int cnt = 0;

					while (q % x == 0)
						q /= x, cnt++;

					mp[x] = cnt;
				}
			}

			if (q > 1)
				mp[q]++;

			ll ans = 1;

			for ( auto x : mp )
			{
				int cnt = 0;
				ll pp = p, ppp = p;

				while (pp % x.first == 0)
				{
					pp /= x.first;
					cnt++;
				}

				ppp /= Pow( x.first, cnt );
				ppp *= Pow( x.first, x.second - 1 );
				ans = max( ans, ppp );
			}

			cout << ans << "\n";
		}
	}
}