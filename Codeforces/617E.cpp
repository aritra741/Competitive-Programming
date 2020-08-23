#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int k;
int arr[100007], pref[100007];
int cnt[1048587];
ll val;

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow - 1);
	int seg = (x < hpow) ? (
	              (y < hpow) ? 0 : 3
	          ) : (
	              (y < hpow) ? 1 : 2
	          );
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct query
{
	int l, r, id;
	ll ord;

	void calcord()
	{
		ord = gilbertOrder(l, r, 21, 0);
	}

} qq[100007];

bool cmp(query &a, query &b) {
	return a.ord < b.ord;
}

inline void jog( int id )
{
	// pref[id] can be equal to pref[id]^k. Hence calculating before adding id's contribution
	val += cnt[ pref[id] ^ k ];
	cnt[ pref[id] ]++;
}

inline void baad( int id )
{
	// pref[id] can be equal to pref[id]^k. Hence calculating after removing id's contribution
	cnt[ pref[id] ]--;
	val -= cnt[ pref[id] ^ k ];
}

ll ans[100007];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q >> k;

	for ( int i = 1; i <= n; i++ )
		cin >> arr[i], pref[i] = pref[i - 1] ^ arr[i];

	for ( int i = 1; i <= q; i++ )
	{
		int l, r;
		cin >> l >> r;

		qq[i].l = l;
		qq[i].r = r;
		qq[i].id = i;
		qq[i].calcord();
	}

	sort( qq + 1, qq + 1 + q, cmp );

	int l = 1, r = 0;
	for ( int i = 1; i <= q; i++ )
	{
		while (r < qq[i].r) jog(++r);
		while (l > qq[i].l - 1) jog(--l);
		while (l < qq[i].l - 1) baad(l++);
		while (r > qq[i].r) baad(r--);

		ans[ qq[i].id ] = val;
	}

	for ( int i = 1; i <= q; i++ )
		cout << ans[i] << "\n";
}