#include <bits/stdc++.h>
#define ll long long 
#define mod 998244353
#define mx 300007
#define pii pair<ll,ll>
#define ff first
#define ss second
using namespace std;

ll f[mx], inv[mx];

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

	for( ll i=2;i<mx;i++ )
		f[i]= (f[i-1]*i)%mod,
		inv[i]= Pow(f[i],mod-2);
}

map<int,int>shuru, shesh;

ll ncr( ll n, ll r )
{
	if(r>n)
		return 0;

	ll upor= f[n];
	ll nich= ( inv[r]*inv[n-r] )%mod;

	return (upor*nich)%mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init();

	ll n,k;
	cin>>n>>k;

	pii arr[n+7];

	for( int i=0;i<n;i++ )
		cin>>arr[i].ff>>arr[i].ss, shuru[ arr[i].ff ]++, shesh[ arr[i].ss+1 ]++, shuru[ arr[i].ss+1 ];

	int ongoing= 0;
	ll ans= 0;

	for( auto x: shuru )
	{
		ongoing-= shesh[x.first];

		for( int i=0;i<x.second;i++ )
			ans= ( ans+ncr( ongoing, k-1 ) )%mod, ongoing++;
	}

	cout<< ans <<"\n";
}








