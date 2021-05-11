#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		if( !(n&(n-1)) )
		{
			cout<<"-1\n";
			continue;
		}

		ll ans= 0;

		for( ll i=0;i<31;i++ )
		{
			ll x= 1LL<<i;
			ll gap= x*2;

			ans+= ((n-x+gap)/gap)*x;

			// cout<<x<<" "<<((n-x+gap)/gap)<<endl;
		}

		cout<<ans-1<<"\n";
	}
}