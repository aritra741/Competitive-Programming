#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n;
	cin>>n;

	ll arr[n+5];
	set<ll>st;

	for( int i=0;i<n;i++ )
	{
		cin>>arr[i];

		for( ll j=0;j<32;j++ )
			if( arr[i]&(1LL<<j) )
				st.insert(j);
	}

	ll x= 0;

	for( auto y: st )
		x+= 1LL<<y;

	ll ans= 0;

	for( int i=0;i<n;i++ )
		ans= max( ans, x^arr[i] );

	cout<< ans <<"\n";
}
