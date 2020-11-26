#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll,int>mpsuff, mppre;
ll pre[100007], suff[100007];

int main()
{
	int n;
	cin>>n;

	int arr[n+5];
	ll tot= 0;

	for( int i=1;i<=n;i++ )
		cin>>arr[i], tot+= arr[i];

	if(tot&1)
		return cout<<"NO\n", 0;

	for( int i=n;i>=1;i-- )
		suff[i]= suff[i+1]+arr[i];

	for( int i=1;i<=n;i++ )
		mpsuff[suff[i]]= i;

	for( int i=1;i<=n;i++ )
		pre[i]= pre[i-1]+arr[i];

	for( int i=n;i>=1;i-- )
		mppre[pre[i]]= i;

	mppre[0]= 0;
	mpsuff[0]= n+1;
	
	if( mpsuff[tot/2] or mppre[tot/2] )
		return cout<<"YES\n", 0;

	for( int i=1;i<=n;i++ )
		if( mpsuff[(tot/2)-arr[i]]>i or( mppre.find((tot/2)-arr[i])!=mppre.end() and mppre[(tot/2)-arr[i]]<i ) )
			return cout<<"YES\n", 0;

	return cout<<"NO\n", 0;			
}