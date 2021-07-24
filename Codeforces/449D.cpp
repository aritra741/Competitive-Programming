#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

ll dp[25][(1<<20)+7];

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
		cin>>arr[i], dp[0][arr[i]]++;

	for( int j=1;j<=20;j++ )
	{
		for( int i=(1<<20);i>=1;i-- )
		{
			if(!(i&(1<<(j-1))))
				dp[j][i]= (dp[j-1][i]+dp[j-1][i|(1<<(j-1))])%mod;
			else
				dp[j][i]= dp[j-1][i];	
		}
	}

	ll ans= Pow( 2, n );
	ans= (ans-1)%mod;
	ans= (ans+mod)%mod;

	for( int i=1;i<=(1<<20);i++ )
	{
		ll now=  Pow( 2, dp[20][i] );
		now= (now-1)%mod;
		now= (now+mod)%mod;

		if( __builtin_popcount(i)&1 )
			ans= (ans-now)%mod, ans= (ans+mod)%mod;
		else
			ans= (ans+now)%mod;
	}

	cout<< ans <<"\n";
}