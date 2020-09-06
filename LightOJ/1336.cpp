#include <bits/stdc++.h>
#define ll long long
#define mx 1000007
using namespace std;

ll sqrtll( ll n )
{
	ll x= sqrt(n);

	ll ans= x;
	for( ll i=max(0LL,x-3);i<=min(n,x+3);i++ )
		if( i*i<=n )
			ans= i;

	return ans;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for( int t=1;t<=tc;t++ )
	{
		ll n;
		scanf("%lld", &n);

		ll ans= n- sqrtll(n)- sqrtll(n/2);

		printf("Case %d: %lld\n", t, ans);
	}	
}
