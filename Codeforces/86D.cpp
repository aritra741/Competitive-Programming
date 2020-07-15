#include<bits/stdc++.h>
#define mx1 200007
#define mx2 1000007
#define k 450
#define ll long long
#define sf(x) scanf("%d", &x)
#define pf(x) printf("%lld\n", x)
using namespace std;

int arr[mx1], cnt[mx2];
ll ans[mx1];
ll sum;

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct query
{
    int l,r,id;
    ll ord;

    void calcord()
    {
        ord= gilbertOrder(l,r,21,0);
    }

}qq[mx1];

bool cmp(query &a, query &b){
  return a.ord<b.ord;
}

inline void jog( int id )
{
    sum-= 1LL*cnt[ arr[id] ]*cnt[ arr[id] ]*arr[id];
    cnt[ arr[id] ]++;
    sum+= 1LL*cnt[ arr[id] ]*cnt[ arr[id] ]*arr[id];
}

inline void baad( int id )
{
    sum-= 1LL*cnt[ arr[id] ]*cnt[ arr[id] ]*arr[id];
    cnt[ arr[id] ]--;
    sum+= 1LL*cnt[ arr[id] ]*cnt[ arr[id] ]*arr[id];
}

int main()
{
    int n,q;
    sf(n);
    sf(q);

    for( int i=1;i<=n;i++ )
        sf(arr[i]);

    for( int i=1;i<=q;i++ )
        sf(qq[i].l),
        sf(qq[i].r),
        qq[i].id= i,
        qq[i].calcord();

    sort( qq, qq+q, cmp );

    int l= 0, r= 0;

    for( int i=1;i<=q;i++ )
    {
        while(l<qq[i].l) baad(l++);
        while(r<qq[i].r) jog(++r);
        while(l>qq[i].l) jog(--l);
        while(r>qq[i].r) baad(r--);

        ans[ qq[i].id ]= sum;
    }

    for( int i=1;i<=q;i++ )
        pf(ans[i]);
}
