#include <bits/stdc++.h>
using namespace stdl;

ll n,k,m;
ll arr[1007];
ll sum[1007];

ll Pow( ll x, ll y, ll mod )
{
	ll res= 1%mod;

	while(y>0)
	{
		if(y&1)
			res= (res*x)%mod;
		x= (x*x)%mod;
		y>>= 1;
	}

	return res;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for( int t=1;t<=tc;t++ )
	{
		scanf("%lld", &n, &k, &m);

		for( int i=0;i<n;i++ )
			scanf("%lld", &arr[i]);

		for( int i=1;i< )

		ll ans= 0;


	}
}