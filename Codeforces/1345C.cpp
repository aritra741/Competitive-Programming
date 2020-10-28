#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		int arr[n+5];
		map<int,int>mp;

		for( int i=0;i<n;i++ )
		{
			cin>>arr[i], mp[i]++;

			arr[i]%= n;

			if(arr[i]<n)
				arr[i]+= n;
		}
		
		bool f= 1;

		for( int i=0;i<n;i++ )
		{
			mp[i]--;
			mp[(i+arr[i])%n]++;			
		}

		for( auto x: mp )
			if(x.second>1)
				f= 0;

		if(f)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}	
}