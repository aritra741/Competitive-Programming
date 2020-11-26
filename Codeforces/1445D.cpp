#include <bits/stdc++.h>
#define mod 998244353
#define mx 300007
#define ll long long
using namespace std;

ll F[mx], inv[mx];

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

void init( int n )
{
	F[0]= F[1]= inv[0]= inv[1]= 1;

	for( ll i=2;i<=n;i++ )
		F[i]= (i*F[i-1])%mod,
		inv[i]= Pow( F[i], mod-2 );
}

int main()
{
	int n;
	cin>>n;
	n*= 2;

	init(n+5);

	int arr[n+5];

	for( int i=1;i<=n;i++ )
		cin>>arr[i];

	sort( arr+1, arr+n+1 );

	ll tot= 0;

	for( int i=1;i<=n/2;i++ )
		tot= (tot-arr[i]+mod)%mod;
	for( int i=n/2+1;i<=n;i++ )
		tot= (tot+arr[i])%mod;
	
	tot= (tot*F[n])%mod;
	tot= (tot*((inv[n/2]*inv[n/2])%mod))%mod;

	cout<< tot <<endl;
}	
