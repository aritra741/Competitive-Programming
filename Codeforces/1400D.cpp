#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cnt[3007][3007];

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		int arr[n+7];

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		for( int i=1;i<=n;i++ )
			for( int j=1;j<=n;j++ )
				cnt[i][j]= 0;

		ll ans= 0;
		for( int i=0;i<n;i++ )
		{
			for( int j=i+1;j<n;j++ )
				ans+= cnt[arr[i]][arr[j]];

			for( int j=0;j<i;j++ )
				cnt[arr[j]][arr[i]]++;
		}

		cout<< ans <<"\n";
	}
}