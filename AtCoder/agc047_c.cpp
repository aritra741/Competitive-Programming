#include <bits/stdc++.h>
#define pii pair <int,int>
#define ff first
#define ss second
#define mx 200007
#define ll long long
#define mod 200003
using namespace std;

int main()
{
	int n;
	cin>>n;

	int arr[n+5];

	ll sum= 0;

	for( int i=0;i<n;i++ )
		cin>>arr[i];

	ll ans= 0;

	for( int i=0;i<n;i++ )
	{
		ll now= (arr[i]*sum)%mod;

		cout<<i<<" "<<now<<endl;

		ans= (ans+now);
		sum= (sum+arr[i])%mod;
	}

	cout<<ans;
}