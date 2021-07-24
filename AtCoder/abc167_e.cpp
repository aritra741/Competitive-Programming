#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mx 200007
#define mod 998244353
#define ll long long
using namespace std;

ll f[mx+7], inv[mx+7];

ll Pow( ll x, ll y )
{
	ll res= 1;

	while(y>0)
	{
		if(y&1)
			res= (res*x)%mod;
		x= (x*x)%mod;
		y>>= 1;
	}

	return res;
}

void init()
{
	f[0]= f[1]= inv[0]= inv[1]= 1;

	for( int i=2;i<=mx;i++ )
		f[i]= (f[i-1]*i)%mod;
	inv[mx]= Pow( f[mx], mod-2 );
	for( int i=mx-1;i>1;i-- )
		inv[i]= ( inv[i+1]*(i+1) )%mod;
}

ll ncr( ll n, ll r )
{
	ll up= f[n];
	ll down= (inv[r]*inv[n-r])%mod;

	return (up*down)%mod;
}

int main()
{
	init();
	fast;

	ll n,m,k;
	cin>>n>>m>>k;

	ll ans= 0;

	for( int i=0;i<=k;i++ )
	{
		ll tot= (m*ncr( n-1, n-i-1 ))%mod;
		tot= ( tot*Pow( m-1, n-i-1 ) )%mod;
		ans= (ans+tot)%mod;
	}

	cout<< ans;
}