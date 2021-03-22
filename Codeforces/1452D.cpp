#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define mx 400007
using namespace std;

ll f[mx], inv[mx];

ll Pow( ll x, ll y )
{
	ll res= 1;

	while(y>0)
	{
		if(x&1)
			res= (res*x)%mod;
		x= (x*x)%mod;
		y>>= 1;
	}

	return res;
}

void init()
{
	f[0]= f[1]= inv[0]= inv[1]= 1;

	for( ll i=2;i<mx;i++ )
		f[i]= ( i*f[i-1] )%mod,
		inv[i]= Pow( f[i], mod-2 );
}

int main()
{
	init();

	int n;
	cin>>n;

	ll ways= 0;

	for( int k=1;k<=n;k++ )
	{
		if( (n+k)&1 )
			continue;
		ll upor= f[(n+k)/2-1];
		ll nich= ( inv[n]*inv[k-1] )%mod;
		ll tot= (upor*nich)%mod;

		ways= ( ways+tot )%mod;
	}

	ll totways= Pow( 2, n );
	totways= Pow( totways, mod-2 );

	ll ans= (ways*totways)%mod;

	cout<< ans <<"\n";
}