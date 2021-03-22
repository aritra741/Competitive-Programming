#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	int t = 0;

	while (tc--)
	{
		int n,k;
		cin>>n>>k;

		int arr[n+5];

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		ll cnt= 0, tot= 0, ans= 1e9;

		for( int i=0;i<k;i++ )
			if(arr[i])
				cnt++, tot++;

		ans= cnt;
		for( int i=k;i<n;i++ )
		{
			if(arr[i-k])
				cnt--;
			if(arr[i])
				cnt++, tot++;

			ans= min( ans, cnt );
		}
		
		cout<< ((ans*(ans+1))/2)+tot-ans <<"\n";
	}
}