#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll suff[300007];

int main()
{
	int n,k;
	cin>>n>>k;

	ll arr[n+7];

	for( int i=1;i<=n;i++ )
		cin>>arr[i];

	suff[n+1]= 0;

	for( int i=n;i>=1;i-- )
		suff[i]= arr[i]+suff[i+1];

	sort( suff+2, suff+n+1, greater<ll>() );

	ll ans= suff[1];

	for( int i=2;i<=k;i++ )
		ans+= suff[i];

	cout<< ans <<"\n";
}