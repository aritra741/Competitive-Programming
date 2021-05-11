#include <bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define N 1200007
using namespace std;

ll qpow(ll n, ll k, ll mod) {
	ll ans = 1; assert(k >= 0); n %= mod; while (k > 0) {
		if (k & 1)
			ans = (ans * n) % mod; n = (n * n) % mod; k >>= 1;
	} return ans % mod;
}
const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int invp1, invp2;
pii pw[N], invpw[N];
void pre()
{
	pw[0] = {1, 1};
	for (int i = 1; i < N; i++) {
		pw[i].F = 1LL * pw[i - 1].F * p1 % MOD1;
		pw[i].S = 1LL * pw[i - 1].S * p2 % MOD2;
	}
	invp1 = qpow(p1, MOD1 - 2, MOD1);
	invp2 = qpow(p2, MOD2 - 2, MOD2);
	invpw[0] = {1, 1};
	for (int i = 1; i < N; i++) {
		invpw[i].F = 1LL * invpw[i - 1].F * invp1 % MOD1;
		invpw[i].S = 1LL * invpw[i - 1].S * invp2 % MOD2; 
	}
}
///returns hash of string s
pii get_hash(string s)
{
	int n = s.size();
	pii ans = {0, 0};
	for (int i = 0; i < n; i++) {
		ans.F = (ans.F + 1LL * pw[i].F * s[i] % MOD1) % MOD1;
		ans.S = (ans.S + 1LL * pw[i].S * s[i] % MOD2) % MOD2;
	}
	return ans;
}
struct RollingHash
{
	int n;
	string s;///0-indexed
	vector<pii>hs;///1-indexed
	void init(string _s)
	{
		n = _s.size();
		s = _s;
		hs.push_back({0, 0});
		for (int i = 0; i < n; i++) {
			pii p;
			p.F = (hs[i].F + 1LL * pw[i].F * s[i] % MOD1) % MOD1;
			p.S = (hs[i].S + 1LL * pw[i].S * s[i] % MOD2) % MOD2;
			hs.push_back(p);
		}
	}
///returns hash of substring [l....r],1-indexed
	pii get_hash(int l, int r)
	{
		pii ans;
		ans.F = (hs[r].F - hs[l-1].F + MOD1) % MOD1 * 1LL * invpw[l-1].F % MOD1;
		ans.S = (hs[r].S - hs[l-1].S + MOD2) % MOD2 * 1LL * invpw[l-1].S % MOD2;
		return ans;
	}
///returns hash of total string
	pii get()
	{
		return get_hash(1, n);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	pre();

	for( int t=1;t<=tc;t++ )
	{
		RollingHash h1,h2;
		int k;
		string s,p;
		cin>>s>>p;
		cin>>k;

		h1.init(s);
		h2.init(p);

		int ans= 0;

		for( int i=0;i<s.size();i++ )
		{
			if( i+p.size()-1>=s.size() )
				break;

			int l= i, r= i+p.size()-1;
			bool f= 0;
			int agey= l;
			// cout<<i<<": \n";
			int covered= 0;
			int cnt= 0;

			for( int j=0;j<=k;j++)
			{
				int mis= 0;
				
				// cout<<j<<" range "<<l<<" "<<r<<endl;
				while(l<=r)
				{
					int mid= (l+r)/2;

					// cout<<"eikhane "<<j<<" "<<agey+1<<" "<<mid+1<<" "<<" "<<covered+1<<" "<<mid-i+1<<" "<<(h1.get_hash(agey+1, mid+1)==h2.get_hash(covered+1, mid-i+1))<<endl;
					// cout<<l+1<<" theke "<<mid+1<<" "<<covered+1<<" theke "<<mid-l+1<<endl;
					if( h1.get_hash(agey+1, mid+1)!=h2.get_hash(covered+1, mid-i+1)  )
						mis= mid+1, r= mid-1;
					else
						l= mid+1;
				}

				// cout<<" "<<j<<" "<<mis<<endl;
				if(!mis)
				{
					f= 1;
					break;
				}
				else
					cnt++;

				covered+= mis-agey;
				l= mis;
				agey= l;
				r= i+p.size()-1;
			}

			// cout<<i<<" "<<cnt<<" "<<f<<endl;

			if( cnt<=k or f )
				ans++;
		}

		cout<<"Case "<<t<<": "<<ans<<"\n";
	} 
}