#include <bits/stdc++.h>
#define pii pair <int,int>
#define ff first
#define ss second
#define mx 200007
#define ll long long
#define mod 998244353
using namespace std;

// 1-indexed, [1, n]
template<class T>
class BIT {
    T bit[mx];
    int n;

public:
    BIT() {
        n = mx;
        memset(bit, 0, sizeof(bit));
    }

    T sum(int i) {
        ++i;
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, T x) {
        ++i;
        while (i < n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    void sub(int i, T x) {
        ++i;
        while (i < n) {
            bit[i] -= x;
            i += i & -i;
        }
    }


};

int quadrant[mx][4];
ll pw[mx];

void init()
{
	pw[0]= 1;

	for( int i=1;i<mx;i++ )
		pw[i]= (pw[i-1]*2)%mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();

	int n;
	cin>>n;

	pii arr[n+5];
	map<int,int>mpx,mpy;

	for( int i=0;i<n;i++ )
		cin>>arr[i].ff>>arr[i].ss, mpx[arr[i].ff], mpy[arr[i].ss];

	int cnt= 0;

	for( auto x: mpx )
		mpx[x.ff]= ++cnt;

	cnt= 0;

	for( auto y: mpy )
		mpy[y.ff]= ++cnt;

	for( int i=0;i<n;i++ )
		arr[i].ff= mpx[arr[i].ff], arr[i].ss= mpy[arr[i].ss];

	sort( arr, arr+n );

	BIT<int>t1,t2;

	for( int i=0;i<n;i++ )
	{
		int tot= t1.sum(arr[i].ss-1);
		quadrant[i][0]= tot;
		quadrant[i][1]= i-tot;

		t1.add(arr[i].ss, 1);
	}

	reverse(arr,arr+n);

	for( int i=0;i<n;i++ )
	{
		int tot= t2.sum(arr[i].ss-1);
		quadrant[n-i-1][2]= tot;
		quadrant[n-i-1][3]= i-tot;

		t2.add(arr[i].ss, 1);
	}

	ll ans= 0;

	for( int i=0;i<n;i++ )
	{
		ll ekhon= pw[n];
		int baame= pw[i];
		int daane= pw[n-i-1];
		int upore= pw[quadrant[i][1]+quadrant[i][3]];
		int niche= pw[quadrant[i][0]+quadrant[i][2]];

		ll tot= (0LL+baame+daane+upore+niche)%mod;

		ekhon= (((ekhon-tot)%mod)+mod)%mod;

		ll uporeBaame= pw[quadrant[i][1]];
		ll uporeDaane= pw[quadrant[i][3]];
		ll nicheBaame= pw[quadrant[i][0]];
		ll nicheDaane= pw[quadrant[i][2]];

		tot= ( uporeBaame+uporeDaane+nicheDaane+nicheBaame )%mod;

		ekhon+= tot;
		ekhon%= mod;

		ans= (ans+ekhon)%mod;
		ans= ((ans-1)%mod+mod)%mod;
	}

	cout<<ans;
}
