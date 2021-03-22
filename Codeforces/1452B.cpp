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

		ll arr[n+5];
		ll sum= 0, mx= 0;

		for( int i=1;i<=n;i++ )
			cin>>arr[i], sum+= arr[i], mx= max(mx,arr[i]);

		ll bhaag= n-1;
		ll tot= (sum+bhaag-1)/bhaag;
		tot= max(tot,mx);
		tot*= bhaag;

		cout<< tot-sum <<"\n";
	}
}