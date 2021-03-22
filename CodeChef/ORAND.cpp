
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define MX (1 << 22)
#define OR 0
#define AND 1
#define XOR 2
#define mx MX+7
using namespace std;

int in1[1 << 22], in2[1 << 22], ans[1 << 22];
template <typename T>
struct FWT {
	void fwt(T io[], int n, bool f) {
		for (int d = 1; d < n; d <<= 1) {
			for (int i = 0, m = d << 1; i < n; i += m) {
				for (int j = 0; j < d; j++) { /// Don't forget modulo if required
					T x = io[i + j], y = io[i + j + d];
					// 	io[i+j] = (x+y), io[i+j+d] = (x-y);	// xor
					if (!f) {
						io[i + j] = x + y; // and
					}
					else {
						io[i + j + d] = x + y; // or
					}
				}
			}
		}
	}
	void ufwt(T io[], int n, bool f) {
		for (int d = 1; d < n; d <<= 1) {
			for (int i = 0, m = d << 1; i < n; i += m) {
				for (int j = 0; j < d; j++) { /// Don't forget modulo if required
					T x = io[i + j], y = io[i + j + d];
					/// Modular inverse if required here
					// 	io[i+j] = (x+y)>>1, io[i+j+d] = (x-y)>>1; // xor
					if (!f) {
						io[i + j] = x - y; // and
					}
					else {
						io[i + j + d] = y - x; // or
					}
				}
			}
		}
	}
	// a, b are two polynomials and n is size which is power of two
	void convolution(T a[], T b[], int n, bool f) {
		fwt(a, n, f);
		for (int i = 0; i < n; i++) {
			a[i] = 1ll * a[i] * b[i] ;
		}
		ufwt(a, n, f);
	}
	// for a*a
	void self_convolution(T a[], int n) {
		for (int i = 0; i < n; i++)
			a[i] = 1ll * a[i] * a[i] ;
	}
};
FWT<int> fwt;
int a[MX], b[MX];

int main()
{
	int tc;
	scanf("%d", &tc);

	while (tc--)
	{
		int n, m; 
		scanf("%d %d", &n, &m);

		int boro = 0;

		for ( int i = 0; i < n; i++ )
			scanf("%d", &a[i]), boro = max(boro, a[i]);
		for ( int i = 0; i < m; i++ )
			scanf("%d", &b[i]), boro = max(boro, b[i]);

		int lim = 0;
		while ((1 << lim) <= boro)lim++;

		for ( int i = 0; i < (1 << lim); i++ )
			in1[i] = 0, in2[i] = 0, ans[i]= 0;

		in1[0] = 1;
		in2[(1 << lim) - 1] = 1;
		ans[0] = 1;

		for ( int i = 0; i < n; i++ )
			in1[a[i]] = 1;
		for ( int i = 0; i < m; i++ )
			in2[b[i]] = 1;

		fwt.fwt(in1, 1 << lim, true);
		fwt.fwt(in2, 1 << lim, false);

		for ( int i = 0; i < lim + lim; i++ )
		{
			fwt.convolution(ans, in1, 1 << lim, true );

			for ( int j = 0; j < (1 << lim); j++ )
				if (ans[j] > 1)
					ans[j] = 1;

			fwt.convolution(ans, in2, 1 << lim, false );

			for ( int j = 0; j < (1 << lim); j++ )
				if (ans[j] > 1)
					ans[j] = 1;

			// cout<< accumulate(ans.begin(),ans.begin()+(1<<lim),0)<<endl;;
		}

		int tot = 0;

		for ( int i = 0; i < (1 << lim); i++ )
			tot += (ans[i] > 0);

		printf("%d\n", tot);
	}
}