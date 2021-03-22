#include <bits/stdc++.h>
#define mx 1000007
#define ll long long
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

bool check(int mask, int pos) {return mask & (1 << pos);}
int SET(int mask, int pos) {return mask | (1 << pos);}
int FLIP(int mask, int pos) {return mask ^ (1 << pos);}
int reset(int mask, int pos) {return mask & ~(1 << pos);}

bool arr[mx];
int prime[mx];
int cnt = 0;
vector<ll> Q;
ll Mx;

ll sq( ll n )
{
	ll s = sqrt(n);

	if ( (s - 1) * (s - 1) == n )
		return s - 1;
	if ( (s + 1) * (s + 1) == n )
		return s + 1;
	return s;
}

void sieve()
{
	prime[cnt++] = 2;

	for ( ll i = 3; i < mx; i += 2 )
	{
		if (!arr[i])
		{
			prime[cnt++] = i;

			for ( ll j = i * i; j < mx; j += 2 * i )
				arr[j] = 1;
		}
	}
}

ll mulmod(ll a, ll b, ll c)
{
	ll x = 0, y = a % c;
	while (b)
	{
		if (b & 1)
			x = (x + y) % c;
		y = (y << 1) % c;
		b >>= 1;
	}
	return x % c;
}

ll mul(ll a, ll b, ll p)
{
	ll tmp = (a * b - (ll)((long double)a / p * b + 1e-8) * p);
	return tmp < 0 ? tmp + p : tmp;
}

ll bigmod( ll x, ll y, ll m )
{
	ll res = 1 % m;

	while (y > 0)
	{
		if ( y & 1 )
			res = mulmod( res, x, m );
		x = mulmod( x, x, m );
		y >>= 1;
	}

	return res % m;
}

bool isPrime(ll n)
{
	if ( n == 1 )
		return 0;
	if ( n == 2 )
		return 1;
	ll d = n - 1;
	int s = 0;

	while (d % 2 == 0)
	{
		s++;
		d >>= 1;
	}

	// It's guranteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)
	int a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };

	for ( int i = 0; i < 9; i++ )
		if ( n == a[i] )
			return 1;

	for (int i = 0; i < 9; i++)
	{
		bool comp = bigmod(a[i], d, n) != 1;
		if (comp)
			for (int j = 0; j < s; j++)
			{
				ll fp = bigmod(a[i], (1ll << (ll)j) * d, n);
				if (fp == n - 1)
				{
					comp = false;
					break;
				}
			}
		if (comp)
			return false;
	}
	return true;
}

ll rho(ll n, ll c)
{
	ll k = 2, x = rand() % n, y = x, p = 1;
	for (ll i = 1; p == 1; i++)
	{
		x = (mul(x, x, n) + c) % n;
		p = y > x ? y - x : x - y;
		p = __gcd(n, p);
		if (i == k)
			y = x, k += k;
	}
	return p;
}
void solve(ll n)
{
	if (n == 1)
		return;
	if (isPrime(n))
	{
		Mx = max(n, Mx);
		return;
	}
	ll t = n;
	while (t == n)
		t = rho(n, rand() % (n - 1) + 1);
	solve(t);
	solve(n / t);
}


int nn, casio = 1;
vector<int>st;
int dp[(1 << 15) + 5];
int vis[(1 << 15) + 5];

int dp_func(int mask)
{
	if (mask == (1 << nn) - 1) {
		return 0;
	}
	if (vis[mask] == casio) {
		return dp[mask];
	}
	vis[mask] = casio;
	int ret = 1e9;
	for (int i = 0; i < st.size(); i++) {
		if (mask != (mask | st[i])) {
			ret = min(ret, 1 + dp_func(mask | st[i]));
		}
	}
	return dp[mask] = ret;
}

int main()
{
	sieve();
	int n, t;
	ll x, arr[50005];
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		bool one= 0;
		scanf("%d%lld", &n, &x);
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);

			if(arr[i]==1)
				one= 1;
		}

		if(x==1)
		{
			int ans= -1;
			if(one)
				ans= 1;
			printf("Case %d: %d\n", tc, ans);
			continue;
		}

		vector<pair<ll, int>>prime_x;

		while (x != 1)
		{
			Mx = 0;
			ll tmp = 0;
			solve(x);
			while (x % Mx == 0)
				x /= Mx, ++tmp;
			prime_x.push_back({Mx, tmp});
		}

		st.clear();
		for (int i = 0; i < n; i++) {
			x = arr[i];
			bool flag = 0;
			int mask = 0;
			bool f= 1;
			for (int i = 0; i < prime_x.size(); i++) {
				pair<ll, int>pp = prime_x[i];
				int count = 0;
				while (x % pp.first == 0) {
					count++;
					x /= pp.first;
				}
				if (count == pp.second) {
					mask = SET(mask, i);
				}
				else if( count>pp.second )
					f= 0;
			}
			if (x == 1ll && mask && f) {
				st.push_back(mask);
			}
		}
		sort(st.begin(), st.end());
		st.resize(unique(st.begin(), st.end()) - st.begin());
		sort(st.begin(), st.end());
		st.erase(unique(st.begin(), st.end()), st.end());
		nn = prime_x.size();
		int mp[(1 << 15) + 5] = {0};
		for (int i = 0; i < st.size(); i++) {
			mp[st[i]] = 1;
		}
		for (int i = 0; i < st.size(); i++) {
			int nnn = st[i];
			for (int s = nnn; s > 0; s = (s - 1)&nnn) {
				if (s == nnn)
					continue;
				mp[s] = 0;
			}
		}
		st.clear();
		for (int i = 0; i < (1 << nn); i++) {
			if (mp[i])
				st.push_back(i);
		}
		int ans = dp_func(0);

		if (ans > st.size()) ans = -1;
		printf("Case %d: %d\n", tc, ans);
		casio++;
	}
}