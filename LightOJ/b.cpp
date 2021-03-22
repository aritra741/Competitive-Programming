#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;
	int cnt= 1;

	while(tc--)
	{
		int n,m;
		cin>>n>>m;

		int arr[n+5];

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		sort( arr, arr+n );

		int last= -1;
		long long ans= 0;

		int brr[m+5];

		for( int i=0;i<m;i++ )
		{
			cin>>brr[i];
		}

		sort( brr, brr+m );

		for( int i=0;i<m;i++ )
		{	
			int x= brr[i];
			last+= x;
			ans+= arr[last]+x*20-20;
		}

		cout<<"Case "<<cnt++<<": "<< ans <<"\n";
	}
}