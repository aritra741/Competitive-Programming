#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define mx 1000000
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

ll dp[mx+7], f[mx+7];

ll Pow( ll x, ll y )
{
	ll res= 1;

	while(y>0)
	{
		if(y&1)
			res= (res*x)%mod;
		x= (x*x)%mod;
		y>>= 1;
	}

	return res;
}

int main()
{
	fast;

	int n;
	cin>>n;

	int arr[n+5];

	for( int i=1;i<=n;i++ )
		cin>>arr[i], f[arr[i]]++;

	for( int i=1;i<=mx;i++ )
		for( int j=i*2;j<=mx;j+=i )
			f[i]= (f[i]+f[j])%mod;

	ll ans= 0;

	for( int i=mx;i>=2;i-- )
	{
		if(f[i])
			dp[i]= ( f[i]*Pow( 2, f[i]-1 ) )%mod;
		
		for( int j=i*2;j<=mx;j+=i )
			dp[i]= ( dp[i]-dp[j] )%mod, dp[i]= ( dp[i]+mod )%mod;

		ans= ( ans+dp[i]*i )%mod;
	}	

	cout<< ans;
}