#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
#define mx 30007
#define pii pair<ll,ll>
#define pci pair<int,int>
#define ff first
#define ss second
#define piii pair<int,pii>
using namespace std;

int main()
{
	ll arr[6];

	for( int i=0;i<6;i++ )
		cin>>arr[i];

	ll n;
	cin>>n;

	if(n==1)
		return cout<<"0\n", 0;

	ll brr[n+5];
	std::vector<pii> v;

	for( int i=0;i<n;i++ )
	{
		cin>>brr[i];

		for( int j=0;j<6;j++ )
			v.push_back( pii(brr[i]-arr[j], i+1) );
	}

	sort( v.begin(), v.end() );
	map<int,int>mp;
	int i= 0, j= 1;
	ll ans= 1e18;
	mp[v[0].ss]++;
	mp[v[1].ss]++;
	

	while(i<6*n and j<6*n)
	{
		if( i==j )
		{
			j++;
			continue;
		}

		if(mp.size()==n)
		{
			ans= min( ans, 0LL+v[j].ff-v[i].ff );

			mp[v[i].ss]--;

			if(!mp[v[i].ss])
				mp.erase(v[i].ss);

			i++;
			continue;			
		}

		j++;
		mp[v[j].ss]++;
	}

	cout<< ans ;
}