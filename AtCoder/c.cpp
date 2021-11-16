#include <bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

ll lcm(ll x, ll y)
{
	return (x*y)/__gcd(x,y);
}

int main()
{
	fast;

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin>>n;

		ll arr[n+5];

		for( int i=1;i<=n;i++ )
			cin>>arr[i];

		ll till= 1;
		bool f= 1;

		for( int i=1;i<=n;i++ )
		{
			till= lcm(till,i+1);

			if( arr[i]%till==0 )
			{
				f= 0;
				break;
			}
		}

		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}