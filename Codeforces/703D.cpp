#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int arr[1000007], pref[1000007];
int cnt[1000007];
int val;

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

} qq[1000007];

bool cmp(query &a, query &b) {
	return a.ord < b.ord;
}

inline void jog( int id )
{
	cnt[ arr[id] ]++;

	if( cnt[ arr[id] ]&1 and cnt[ arr[id] ]>=3 )
		val^= arr[id];
	else if( cnt[ arr[id] ]%2==0 )
		val^= arr[id]; 
}

inline void baad( int id )
{
	cnt[ arr[id] ]--;

	if( cnt[ arr[id] ]&1 )
		val^= arr[id];
	else if( cnt[ arr[id] ] and cnt[ arr[id] ]%2==0 )
		val^= arr[id];
}

int ans[1000007];

int main()
{
	int n;
	scanf("%d", &n);

	for ( int i = 1; i <= n; i++ )
		scanf("%d", &arr[i]);

	int q;
	scanf("%d", &q);

	for ( int i = 1; i <= q; i++ )
	{
		int l, r;
		scanf("%d %d", &l, &r);

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
		while (l > qq[i].l) jog(--l);
		while (l < qq[i].l) baad(l++);
		while (r > qq[i].r) baad(r--);

		ans[ qq[i].id ] = val;
	}

	for ( int i = 1; i <= q; i++ )
		printf("%d\n", ans[i]);
}