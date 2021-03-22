#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;

	while(scanf("%d %d", &n, &m)==2)
	{
		int arr[n+5], brr[m+5];
		unordered_map<int,int>mp;
		int ans= 0, mx= 2e9;

		for( int i=1;i<=n;i++ )
			cin>>arr[i];

		for( int i=1;i<=m;i++ )
		{
			int x;
			cin>>x;

			for( int j=1;j<=n;j++ )
			{
				if( x-arr[j]>=0 )
				{
					mp[x-arr[j]]++;

					if( mp[x-arr[j]]>ans )
						ans= mp[x-arr[j]], mx= x-arr[j];
					else if( mp[x-arr[j]]>ans and x-arr[j]<mx )
						ans= mp[x-arr[j]], mx= x-arr[j];
				}
			}
		}

		if(mx>1e9)
			mx= 0;
		
		printf("%d\n", mx);
	}
}