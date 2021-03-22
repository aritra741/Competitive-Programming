#include <bits/stdc++.h>
#define mx 5000007
#define mod 100000007
#define ll long long
using namespace std;

int ok[mx];
ll pw[mx][32];
int pr[mx], pre[mx];
int cnt;

ll ans[mx];
ll now = 1;

ll Pow( ll x, ll y )
{
	ll res = 1;

	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}

	return res;
}


int getRemainder(ll num, ll mm) 
{ 
    return (num - mm * (num / mm)); 
} 

void sieve()
{
	ok[0] = ok[1] = 1;

	for ( int i = 1; i < mx; i++ )
		pre[i] = getRemainder((pre[i - 1] + i), mod);

	for ( int i = 2; i < mx; i++ )
	{
		if (!ok[i])
		{
			pr[cnt++] = i;
			ok[i] = i;

			ll x = i;
			ll y = 0;

			for (;;)
			{
				if ( x <= mx*5 )
					pw[i][y++] = x, x *= i;
				else
					break;
			}

			for ( int j = i * 2; j < mx; j += i )
				if (!ok[j])
					ok[j] = i;
		}
	}
}

int main()
{
	sieve();
	int n;

	while (scanf("%d", &n) == 1 and n)
	{
		ll ans = 1;

		for ( int ii = 0; pr[ii] <= n and ii < cnt; ii++ )
		{
			int i = pr[ii];
			// cout<<i<<endl;
			ll tot = 0;
			if (ok[i] == i)
			{
				ll x = i;
				ll cc = 0, cn = 0;
				ll sum = 0;
				ll z = i;

				while (z <= n)
				{
					// cout<<i<<" "<<z<<endl;
					ll bhaag = n / z;
					bhaag--;
					ll now = getRemainder((z * pre[bhaag]), mod);
					sum = getRemainder((sum + now), mod);

					ll baki = getRemainder(n,z);
					baki++;

					now = getRemainder((baki * (n / z)), mod);
					sum = getRemainder((sum + now), mod);

					z*= i;
				}

				sum = getRemainder((sum + 1), mod);
				ans = getRemainder((ans * sum), mod);
			}
		}

		printf("%lld\n", ans);
	}

}