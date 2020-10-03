#include <bits/stdc++.h>
using namespace std;

int arr[100007];

int main()
{
	int n;
	cin>>n;

	for( int i=1;i<=n;i++ )
		cin>>arr[i], arr[i]= (arr[i]-1>=arr[i-1])?arr[i]-1:arr[i];

	bool f= 1;

	for( int i=2;i<=n;i++ )
		if( arr[i]<arr[i-1] )
			f= 0;

	if(f)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}