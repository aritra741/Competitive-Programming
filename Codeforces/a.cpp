#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll n;
	cin>>n;

	ll ans= 0;

	for( ll a=1;a*a*a<=n;a++ )
	{
		ll bc= n/a;

		for( ll b=a;b*b<=bc;b++ )
		{
			ans+= (bc/b)-b+1;
		}
	}

	cout<<ans;
}