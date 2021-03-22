#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define MX (1 << 19)
#define OR 0
#define AND 1
#define XOR 2
#define mx 200007
#define MOD 1000000009
using namespace std;

ll qpow( ll x, ll y )
{
	ll res = 1;

	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % MOD;
		x = (x * x) % MOD;
		y >>= 1;
	}

	return res;
}
// int in = qpow(2, MOD - 2);
int in1[1 << 22], in2[1 << 22], ans[1 << 22];
template <typename T>
struct FWT {
	void fwt(T io[], int n, bool f) {
		for (int d = 1; d < n; d <<= 1) {
			for (int i = 0, m = d << 1; i < n; i += m) {
				for (int j = 0; j < d; j++) { /// Don't forget MODulo if required
					T x = io[i + j], y = io[i + j + d];
					// 	io[i+j] = (x+y), io[i+j+d] = (x-y);	// xor
					if (!f) {
						io[i + j] = x + y; // and
						if (io[i + j] >= MOD)io[i + j] -= MOD;
					}
					else {
						io[i + j + d] = x + y; // or
						if (io[i + j + d] >= MOD)io[i + j + d] -= MOD;
					}
				}
			}
		}
	}
	void ufwt(T io[], int n, bool f) {
		for (int d = 1; d < n; d <<= 1) {
			for (int i = 0, m = d << 1; i < n; i += m) {
				for (int j = 0; j < d; j++) { /// Don't forget MODulo if required
					T x = io[i + j], y = io[i + j + d];
					/// MODular inverse if required here
					// 	io[i+j] = (x+y)>>1, io[i+j+d] = (x-y)>>1; // xor
					if (!f) {
						io[i + j] = x - y; // and
						if (io[i + j] < 0)io[i + j] += MOD;
					}
					else {
						io[i + j + d] = y - x; // or
						if (io[i + j + d] < 0)io[i + j + d] += MOD;
					}
				}
			}
		}
	}
	// a, b are two polynomials and n is size which is power of two
	void convolution(T *a, T *b, int n, bool f) {

		fwt(a, n, f);
		for (int i = 0; i < n; i++) {
			a[i] = 1ll * a[i] * b[i] % MOD;
		}
		ufwt(a, n, f);
	}
	// for a*a
	void self_convolution(T a[], int n) {
		for (int i = 0; i < n; i++)
			a[i] = 1ll * a[i] * a[i] % MOD;
	}
};
FWT<int> fwt;

int a[MX + 7], b[MX + 7];

int main()
{
	int n;
	scanf("%d", &n);

	int m;
	scanf("%d", &m);

	ll nich = m;

	for ( int i = 0; i < m; i++ )
	{
		int x;
		scanf("%d", &x);

		a[x]++;
	}

	// fwt.fwt(a, MX, false);

	for ( int j = 0; j < 3; j++ )
	{
		int y;
		scanf("%d", &y);

		nich *= y;
		nich %= MOD;

		memset(b,0,sizeof(b));

		for ( int i = 0; i < y; i++ )
		{
			int x;
			scanf("%d", &x);

			b[x]++;
		}

		fwt.fwt(b, MX, false);
		fwt.convolution(a, b, MX, false);
	}

	nich = qpow(nich, MOD - 2);

	for ( int i = 0; i < (1 << n); i++ )
		printf("%lld\n", (a[i]*nich) % MOD );

}