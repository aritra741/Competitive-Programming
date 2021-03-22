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

		int arr[n+5];
		int mp[6]= {0};

		ll ans= 0;

		for( int i=0;i<n;i++ )
			cin>>arr[i], arr[i]%= 6, ans+= mp[(6-arr[i])%6], mp[arr[i]]++;

		cout<< ans <<"\n";
	}
}