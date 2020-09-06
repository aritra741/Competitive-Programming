#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, k;
ll F[1000007]; // Factorial excluding multiples of p
int pr[15], pw[15];
int sz;

ll ext_gcd ( ll A, ll B, ll *X, ll *Y ) {
	ll x2, y2, x1, y1, x, y, r2, r1, q, r;
	x2 = 1; y2 = 0;
	x1 = 0; y1 = 1;
	for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
		q = r2 / r1;
		r = r2 % r1;
		x = x2 - (q * x1);
		y = y2 - (q * y1);
	}
	*X = x2; *Y = y2;
	return r2;
}

ll crt(ll *A, ll *M, ll n) {
	ll a1 = A[0];
	ll m1 = M[0];
	for ( ll i = 1; i < n; i++ ) {
		ll a2 = A[i];
		ll m2 = M[i];

		ll g = __gcd(m1, m2);
		if ( a1 % g != a2 % g ) return -1;
		ll p, q;
		ext_gcd(m1 / g, m2 / g, &p, &q);

		ll mod = m1 / g * m2;
		ll x = (a1 * (m2 / g) * q + a2 * (m1 / g) * p) % mod;
		a1 = x;
		if (a1 < 0) a1 += mod;
		m1 = mod;
	}
	return a1;
}

ll Pow( ll x, ll y, ll mod )
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

void factorize(int m)
{
	sz = 0;
	for ( int i = 2; i * i <= m; i++ )
	{
		if (m % i)
			continue;
		pr[sz] = i;
		int x = 1;

		while (m % i == 0)
			m /= i, x *= i;

		pw[sz++] = x;
	}

	if(m>1)
		pr[sz]= m, pw[sz++]= m;
}

void initialize_factorial( int p, int pwr )
{
	F[0]= 1;
	for ( int i = 1; i <=pwr; i++ )
	{
		if (i % p)
			F[i] = (F[i - 1] * i) % pwr;
		else
			F[i] = F[i - 1];
	}
}

ll prime_diye_mod( ll n, int p, int pwr )
{
	if(n<=1)
		return 1;
	int block = n / pwr;
	int baki = n % pwr;

	int block_sz = pwr;

	ll mod_val; 

	// Wilson's Theorem
	if (block & 1)
		mod_val = (-1 + pwr) % pwr;
	else
		mod_val = 1 % pwr;

	ll val = (F[baki] * mod_val) % pwr;
	
	return (val * prime_diye_mod( n / p, p, pwr )) % pwr;
}

ll koyta( ll n, ll p )
{
	ll ans = 0;

	while (n)
		ans += n / p, n/= p;

	return ans;
}

ll shob_prime( ll n, ll r )
{
	ll arr[sz];
	ll mm[sz];

	for ( int i = 0; i < sz; i++ )
	{
		initialize_factorial( pr[i], pw[i] );
		ll x = prime_diye_mod( n, pr[i], pw[i] );
		ll y=  (prime_diye_mod( r, pr[i], pw[i] ) * prime_diye_mod( n - r, pr[i], pw[i] )) % pw[i];
		ll xy= (x*Pow(y, (pw[i]-pw[i]/pr[i])-1, pw[i] ) )%pw[i];
		ll tot = koyta(n, pr[i]) - koyta(r, pr[i]) - koyta(n - r, pr[i]);

		arr[i] = (xy * Pow(pr[i],tot,pw[i])) % pw[i];
		mm[i] = pw[i];
	}

	ll ans = crt( arr, mm, sz );

	return ans;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	while (tc--)
	{
		scanf("%lld %lld %lld", &n, &k, &m);
		factorize(m);
		ll x = (n + k - 1) / k;
		ll a = x*k-n;
		ll y = shob_prime( x + a - 1, x-1 );

		printf("%lld %lld\n", x, y);
	}
}