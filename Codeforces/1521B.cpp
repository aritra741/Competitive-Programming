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

		int mn= 2e9, idx= -1;

		int arr[n+5];

		for( int i=1;i<=n;i++ )
		{
			cin>>arr[i];

			if(arr[i]<mn)
				mn= arr[i], idx= i;
		}

		cout<<n-1<<"\n";
		int ans= mn+1;

		for( int i=idx-1;i>=1;i-- )
			cout<<idx<<" "<<i<<" "<<mn<<" "<<ans++<<"\n";

		ans= mn+1;

		for( int i=idx+1;i<=n;i++ )
			cout<<idx<<" "<<i<<" "<<mn<<" "<<ans++<<"\n";
	}
}