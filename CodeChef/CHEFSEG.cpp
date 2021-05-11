#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		ll x, k;
		cin >> x >> k;

		ll now = 0, tot = 0;
		ll pore = 1;

		while (tot + pore < k)
		{
			if (now > 0)
				now *= 2LL, tot += now;
			else
				now = 1, tot = 1;

			pore *= 2LL;
		}

		tot = tot + 1;

		ld dv = (ld)x / tot;
		ll baki = k - tot + 1;

		// cout << now << " " << tot << " " << dv << " " << baki << endl;

		ld pos = dv * (baki - 1);
		pos += dv / 2.0;

		cout << setprecision(10) << fixed << pos << "\n";
	}
}