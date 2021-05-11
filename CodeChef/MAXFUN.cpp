#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		ll arr[n+5];
		ll mx= -2e9, mn= 2e9;

		for( int i=0;i<n;i++ )
			cin>>arr[i], mx= max(mx,arr[i]), mn= min(mn,arr[i]);

		cout<< (mx-mn)*2 <<"\n";
	}
}
