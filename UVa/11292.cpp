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

	int n,m;
	while(cin>>n>>m and n and m)
	{
		int arr[n+5];

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		sort( arr, arr+n );

		multiset<int>ms;

		for( int i=0;i<m;i++ )
		{
			int x;
			cin>>x;

			ms.insert(x);
		}

		int ans= 0;
		bool f= 1;

		for( int i=0;i<n;i++ )
		{
			auto it= ms.lower_bound(arr[i]);

			if(it==ms.end())
			{
				f= 0;
				break;
			}

			ms.erase(it);
			ans+= *it;
		}

		if(f)
			cout<< ans <<"\n";
		else
			cout<< "Loowater is doomed!" <<"\n";
	}
}