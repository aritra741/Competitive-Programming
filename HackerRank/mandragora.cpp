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

		int arr[n+5];

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		sort( arr, arr+n );

		ll sum[n+5];
		sum[n-1]= arr[n-1];

		for( int i=n-2;i>=0;i-- )
			sum[i]= sum[i+1]+arr[i];

		ll s= 1, p= 0;

		for( int i=0;i<n;i++ )
		{
			p= max( p, s*sum[i] );
			s++;
		}

		cout<< p <<"\n";
	}	
}