#include <bits/stdc++.h>
#define ll long long
#define mx 107
using namespace std;

ll fac[mx];
int inv[mx];

ll lucas(int n, int k, int p) {
	
	inv[0]= inv[1]= fac[0]= fac[1]= 1;

	for( int i=2;i<=p;i++ ) 
	{
		fac[i] = (fac[i - 1] * i) % p;
		inv[i] = ((ll)(p - p / i) * inv[p % i]) % p;
	}

	int x, y;
	ll res = 1;
	while (k) {
		x = n % p; y = k % p;
		if (x < y) return 0;
		res *= (fac[x] * inv[fac[y]] * inv[fac[x - y]]) % p;
		res %= p;
		n /= p;
		k /= p;
	}

	return res;
}


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


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,r,m;
		cin>>n>>r>>m;

		std::vector<int> v;

		for( int i=2;i<=50;i++ )
		{
			if(m%i)
				continue;
			v.push_back(i);
			while(m%i==0)
				m/= i;
		}

		ll arr[v.size()+5], mods[v.size()+5];
		int cc= 0;

		for( auto x: v )
		{
			arr[cc]= x;
			mods[cc++]= lucas(n,r,x);
		}

		ll ans= crt( mods, arr, cc );

		cout<< ans <<"\n";
	}
}