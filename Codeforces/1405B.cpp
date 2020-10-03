#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		ll arr[n+7];
		ll kom= 0;

		for( int i=1;i<=n;i++ )
			cin>>arr[i];

		ll cov= 0, ans= 0;
		for( int i=n;i>=1;i-- )
		{
			if( arr[i]<0 )
				cov+= -arr[i];
			else
			{
				ll covered= min( arr[i],cov );
				arr[i]-= covered;
				cov-= covered;
			}
		}

		for( int i=1;i<=n;i++ )
			if( arr[i]>0 )
				ans+= arr[i];

		cout<< ans <<"\n";
	}
}