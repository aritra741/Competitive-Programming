#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n,k;
		cin>>n>>k;

		int arr[n+5];
		bool f= 0, ff= 0;

		for( int i=0;i<n;i++ )
		{
			cin>>arr[i], f= (arr[i]==k)?1:f;

			if(arr[i]>=k )
				for( int j=max(0,i-2);j<i;j++ )
					if( arr[j]>=k )
						ff= 1;
		}

		if(f and n==1)
		{
			cout<<"yes\n";
			continue;
		}

		if(!f or !ff)
		{
			cout<<"no\n";
			continue;
		}

		cout<<"yes\n";
	}
}