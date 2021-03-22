#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define MX (1 << 17)
#define OR 0
#define AND 1
#define XOR 2
#define mx 100007
#define mod 1000000007
using namespace std;

ll qpow( ll x, ll y )
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
int in = qpow(2, mod - 2);
/// Fast Walsh-Hadamard Transformation in n log n
///Beware!!! after the convolution the arrays will not be the same
// again
///array sizes must be same and powers of 2
struct fwht {
	int P1[MX], P2[MX];
	void walsh_transform(int* ar, int n, int flag = AND) {
		if (n == 0) return;
		int i, m = n / 2;
		walsh_transform(ar, m, flag);
		walsh_transform(ar + m, m, flag);

		for (i = 0; i < m; i++) { /// Don't forget to remove modulo if not
// required
			int x = ar[i], y = ar[i + m];
			if (flag == OR) ar[i] = x, ar[i + m] = (x + y) % mod;
			if (flag == AND) ar[i] = (x + y) % mod, ar[i + m] = y;
			if (flag == XOR) ar[i] = (x + y) % mod, ar[i + m] = (x -
				                         y + mod) % mod;
		}
	}
	void inverse_walsh_transform(int* ar, int n, int flag = AND) {
		if (n == 0) return;
		int i, m = n / 2;
		inverse_walsh_transform(ar, m, flag);
		inverse_walsh_transform(ar + m, m, flag);
		for (i = 0; i < m; i++) { /// Don't forget to remove modulo if not
// required
			int x = ar[i], y = ar[i + m];
			if (flag == OR) ar[i] = x, ar[i + m] = (y - x + mod) % mod;
			if (flag == AND) ar[i] = (x - y + mod) % mod, ar[i + m] = y;
			if (flag == XOR) ar[i] = 1LL * (x + y) % mod * in % mod, ar[i + m] =
				                             1LL * (x - y + mod) % mod * in % mod; /// replace modular inverse(in) >> 1 if not required
		}
}
/// For i = 0 to n - 1, j = 0 to n - 1
/// v[i flag j] += A[i] * B[j]
vi convolution(int n, ll *A, ll *B, int flag = AND) {
		assert(__builtin_popcount(n) == 1); /// n must be a power of 2
		for (int i = 0; i < n; i++) P1[i] = A[i];
		for (int i = 0; i < n; i++) P2[i] = B[i];
		walsh_transform(P1, n, flag);
		walsh_transform(P2, n, flag);
		for (int i = 0; i < n; i++) P1[i] = 1LL * P1[i] * P2[i] % mod;
		inverse_walsh_transform(P1, n, flag);
		return vi(P1, P1 + n);
	}
///compute A^k where A*A=A convolution A
	vi pow(int n, int* A, ll k, int flag = AND)
	{
		walsh_transform(A, n, flag);
		for (int i = 0; i < n; i++) A[i] = qpow(A[i], k);
		inverse_walsh_transform(A, n, flag);
		return vi(A, A + n);
	}
} t;

ll a[MX], b[MX];
std::vector<ll> adj[mx], wt[mx];

void dfs( ll u, ll p, ll xx )
{

	a[xx]++;

	// cout<<" "<<u<<" "<<xx<<" "<<a[xx]<<endl;

	for ( ll i = 0; i < adj[u].size(); i++ )
	{
		ll v = adj[u][i];
		ll w = wt[u][i];

		// cout<<u<<" "<<v<<" "<<w<<endl;

		if (v == p)
			continue;

		dfs(v, u, xx ^ w);
	}
}

int main()
{
	ll n;
	scanf("%lld", &n);

	for ( ll i = 1; i < n; i++ )
	{
		ll u, v, w;
		scanf("%lld %lld %lld", &u, &v, &w);

		adj[u].push_back(v);
		adj[v].push_back(u);
		wt[u].push_back(w);
		wt[v].push_back(w);
	}

	dfs(1, 1, 0);

	for ( ll i = 0; i < MX; i++ )
		b[i] = a[i];

	std::vector<ll> ans = t.convolution(MX, a, b, XOR);
	ll tot = 0;

	for ( ll i = 0; i < MX; i++ )
	{
		ll now = ans[i];

		tot+= now*now;
		tot%= mod;

		for ( int j = 0; j < 17; j++ )
		{
			if ( i & (1 << j) )
				tot += (ans[i ^ (1 << j)] * now) % mod;
			else
				tot += (ans[i | (1 << j)] * now) % mod;

			tot %= mod;
		}
	}

	printf("%lld\n", tot);

	for ( ll i = 1; i <= n; i++ )
		adj[i].clear(), wt[i].clear();

	for ( int i = 0; i < MX; i++ )
		ans[i] = 0;
}