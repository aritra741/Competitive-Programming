#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second 
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,m;
		cin>>n>>m;

		pii arr[m+5];

		for( int i=0;i<m;i++ )
			cin>>arr[i].ff>>arr[i].ss;

		ll sum[m+5];

		sort( arr, arr+m );

		sum[m-1]= arr[m-1].ff;
		sum[m]= 0;

		for( int i=m-2;i>=0;i-- )
			sum[i]= arr[i].ff+sum[i+1];

		ll ans= 0;

		if(n<=m)
			for( int i=m-1;i>=m-n;i-- )
				ans+= arr[i].ff;

		for( int i=0;i<m;i++ )
		{
			ll pos= upper_bound( arr, arr+m, pii(arr[i].ss,1e12) )-arr;
			ll totbeshi= m-pos;

			ll tot= 0;

			if(arr[i].ff>arr[i].ss)
				tot-= arr[i].ff, totbeshi--;

			tot+= sum[pos]+arr[i].ss*(n-totbeshi-1)+arr[i].ff;

			totbeshi+= 2;

			if(totbeshi>n)
				continue;

			ans= max(ans,tot);
		}

		cout<< ans <<"\n";
	}	
}