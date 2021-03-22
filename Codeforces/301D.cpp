#include <bits/stdc++.h>
#define mx 200007
#define pii pair<int,int>
#define piii pair<pii,int>
#define ff first
#define ss second
using namespace std;

std::vector<int> v[mx];
int ans[mx];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	int arr[n+5];

	for( int i=1;i<=n;i++ )
		cin>>arr[i];

	std::vector<pii> qq[m+7];
	ll tot= 0;
	
	for( int i=1;i<=m;i++ )
	{
		int l,r;
		cin>>l>>r;
		qq[r].push_back(pii(l,i));
	}

	for( int i=1;i<=n;i++ )
	{
		v[arr[i]].push_back(i);

		for( auto x: qq[i] )
		{
			int l= x.ff;

			for( int j=1;j*j<=arr[i];j++ )
			{
				if(arr[i]%j)
					continue;

				int pos= lower_bound( v[j].begin(), v[j].end(), l )-v[j].begin();
				ans[x.ss]= v[j].size()-pos;

				if( j==arr[i]/j )
					continue;

				int k= arr[i]/j;

				pos= lower_bound( v[k].begin(), v[k].end(), l )-v[k].begin();
				ans[x.ss]+= v[k].size()-pos;

			}
		}
	}

	for( int i=1;i<=m;i++ )
		cout<< ans[i] <<"\n";
}