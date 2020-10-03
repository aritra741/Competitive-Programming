#include <bits/stdc++.h>
using namespace std;

int getval( int x )
{
	if(x==4)
		return 1;
	if(x==8)
		return 2;
	if(x==15)
		return 3;
	if(x==16)
		return 4;
	if(x==23)
		return 5;
	return 6;
}

int main()
{
	int n;
	cin>>n;

	int arr[n+7];
	map<int,int>mp, mp2;

	for( int i=1;i<=n;i++ )
	{
		cin>>arr[i];
		arr[i]= getval(arr[i]);
	}

	int ans= 0, tmp= 1e9;
	for( int i=1;i<=n;i++ )
	{
		mp[ arr[i] ]++;
		if(arr[i]>1)
			mp[ arr[i] ]= min( mp[arr[i]], mp[arr[i]-1] );

		if( arr[i]==6 )
		{
			ans+= mp[ arr[i] ];
			for( int j=1;j<=6;j++ )
				mp[j]-= mp[arr[i]];
		}
	}

	cout<< n-ans*6 <<"\n";
}