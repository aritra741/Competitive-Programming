#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fact[25];

void init()
{
	fact[0] = 1;

	for ( ll i = 1; i <= 20; i++ )
		fact[i] = i * fact[i - 1];
}

int main()
{
	init();

	int tc;
	cin >> tc;

	while (tc--)
	{
		int x, n, k;
		cin >> x >> n >> k;

		if(k==1)
		{
			cout<< x<<" "<< fact[n-1] <<"\n";
			continue;
		}

		ll ans= 0;

		for ( int y = 2; y <= k; y++ )
		{
			ll derangement = 0;
			for ( ll i = 0; i <= y; i++ )
			{
				if (i & 1)
					derangement -= fact[y] / fact[i];
				else
					derangement += fact[y] / fact[i];
			}

			ans+= derangement*fact[n-y];

			cout<< y <<" "<<derangement<<endl;
		}

		cout << x << " " << ans << endl;
	}
}