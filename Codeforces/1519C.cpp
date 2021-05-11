#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
	fast;

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		int u[n+5];
		std::vector<int> v[n+5];
		std::vector<ll> sum[n+5];
		
		for( int i=1;i<=n;i++ )
			cin>>u[i];
		
		for( int i=1;i<=n;i++ )
		{
			int x;
			cin>>x;

			v[u[i]].push_back(x);
		}

		for( int i=1;i<=n;i++ )
			sort( v[i].begin(), v[i].end(), greater<int>() );

		ll ans[n+5];

		for( int i=0;i<=n;i++ )
			ans[i]= 0;

		for( int i=1;i<=n;i++ )
		{
			ll s= 0;
			sum[i].push_back(0);

			for( auto x: v[i] )
				s+= x, sum[i].push_back(s);

			for( int j=1;j<=n;j++ )
			{
				if( j>=sum[i].size() )
					break;

				int idx= (v[i].size()/j)*j;

				ans[j]+= sum[i][idx];
			}
		}

		for( int i=1;i<=n;i++ )
			cout<< ans[i] <<" ";

		cout<<"\n";
	}
}