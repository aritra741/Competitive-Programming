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

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		if(arr[0]<arr[n-1])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}