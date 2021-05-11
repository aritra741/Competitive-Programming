#include <bits/stdc++.h>
#define mx 10000007
#define ll long long
using namespace std;

int spf[mx];
int primes[mx];
int cnt;

void sieve()
{
	spf[1] = 1;
	// phi[1]= 1;
	for ( ll i = 2; i < mx; i++ )
	{
		if ( !spf[i] )
		{
			spf[i] = i;
			// phi[i]= i-1;
			primes[cnt++] = i;
		}
		else
		{
			// int d= i/spf[i];

			// if( d%spf[i] )
			//     phi[i]= phi[d]*( spf[i]-1 );
			// else
			//     phi[i]= phi[d]*spf[i];
		}

		for ( ll j = 0; j < cnt and primes[j] <= spf[i] and i * primes[j] < mx; j++ )
			spf[ primes[j]*i ] = spf[i];
	}
}

int main()
{
	sieve();

	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int c, d, x;
		cin >> c >> d >> x;

		ll ans = 0;

		for ( int i = 1; i * i <= x; i++ )
		{
			int y = i;
			ll now = 1;
			bool f = 0;

			if ( x % y )
				continue;

			// cout<<y<<endl;

			ll baam = 1LL * d * y + x;
			ll lcm = baam/c;
			// cout<<lcm<<endl;

			if ( lcm % i == 0 and baam%c==0 )
			{
				// cout<<"ashe\n";
				unordered_map<int, int>mp1, mp2;
				// cout
				while (spf[lcm] > 1)
				{
					// cout<<lcm<<" "<<spf[lcm]<<endl;
					int cc = 0;
					int p = spf[lcm];

					while (lcm % p == 0)
						cc++, lcm /= p;

					mp1[p] = cc;
				}

				int g = i;

				while (spf[g] > 1)
				{
					int cc = 0;
					int p = spf[g];

					while (g % p == 0)
						cc++, g /= p;

					mp2[p] = cc;
				}

				for ( auto xx : mp1 )
				{
					// cout<<" "<<xx.first<<endl;
					if ( mp2[xx.first] != xx.second )
						now *= 2, f = 1;
				}

				// cout << i << " " << baam << " " << now << endl;
				ans += now;
			}

			y = x / i;
			now = 1;

			if (i == x / i)
				continue;

			baam = 1LL * d * y + x;
			lcm = baam/c;

			cout<<y<<" "<<lcm<<endl;

			if ( c*lcm-d*y==x and lcm % y == 0 and baam%c==0)
			{
				unordered_map<int, int>mp1, mp2;
				while (spf[lcm] > 1)
				{
					int cc = 0;
					int p = spf[lcm];

					while (lcm % p == 0)
						cc++, lcm /= p;

					mp1[p] = cc;
				}

				int g = x / i;

				while (spf[g] > 1)
				{
					int cc = 0;
					int p = spf[g];

					while (g % p == 0)
						cc++, g /= p;

					mp2[p] = cc;
				}

				for ( auto xx : mp1 )
					if ( mp2[xx.first] != xx.second )
						now *= 2, f = 1;

				ans += now;
				// cout << x / i << " " << baam << " " << now << endl;
			}
		}

		cout << ans << "\n";
	}
}