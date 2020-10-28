#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

int a[200007], b[200007];
int suff_min[200007];
map<int,int>shuru,shesh;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	for( int i=1;i<=n;i++ )
		cin>>a[i], suff_min[i]= suff_min[i+1]= 2e9;

	for( int i=n;i>=1;i-- )
		suff_min[i]= min( suff_min[i+1], a[i] );

	for( int i=1;i<=n;i++ )
		shesh[ suff_min[i] ]= i;
	for( int i=n;i>=1;i-- )
		shuru[ suff_min[i] ]= i;
	
	ll ans= 1;

	for( int i=1;i<=m;i++ )
	{
		cin>>b[i];

		if(!shuru[b[i]])
			return cout<<"0\n", 0;
	}

	if( suff_min[1]!=b[1] )
		return cout<<"0\n", 0;

	for( int i=2;i<=m;i++ )
		ans= ( ans*(shesh[b[i]]-shuru[b[i]]+1) )%mod;

	cout<< ans <<"\n";
}