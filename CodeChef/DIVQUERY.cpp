#include <bits/stdc++.h>
#define mx 100007
using namespace std;

std::vector<int> v[mx];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,q;
	cin>>n>>q;

	int arr[n+5];

	for( int i=1;i<=n;i++ )
	{
		cin>>arr[i];

		int x= arr[i];

		for( int j=1;j*j<=x;j++ )
		{
			if( x%j )
				continue;

			if(j>1)
				v[j].push_back(i);

			if( x/j!=j )
				v[x/j].push_back(i);
		}
	}

	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;

		if(k==1)
			cout<<r-l+1<<"\n";
		else
			cout<< upper_bound(v[k].begin(), v[k].end(), r)-lower_bound(v[k].begin(), v[k].end(), l) <<"\n";
	}
}