#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

int dp[3007][3007];
bool vis[3007][3007];

int n, s;
int arr[3007];

ll rec( int i, int rem )
{
	if ( i >= n )
		return 0;

	if( vis[i][rem] )
		return dp[i][rem];

	// cout<<i<<" "<<rem<<endl;

	ll ret = 0;

	if ( rem == s )
	{
		if ( arr[i] <= rem )
		{
			if( arr[i]<rem )
				ret = ( (i+1) * rec( i + 1, rem - arr[i] ) ) % mod;
			else
				ret = (1LL*(i+1)*(n-i))%mod;

			ret= ( ret+rec( i+1, rem ) )%mod;
		}
		else
			ret= rec( i+1, rem );
	}
	else 
	{
		if( arr[i]<=rem )
		{
			if( rem-arr[i] )
				ret = rec( i + 1, rem-arr[i] );
			else 
				ret= n-i;
		}
		ret= ( ret+rec( i+1, rem ) )%mod;
	}

	vis[i][rem]= 1;

	return dp[i][rem]= ret;
}

int main()
{
	cin>>n>>s;

	for( int i=0;i<n;i++ )
		cin>>arr[i];

	cout<< rec( 0, s );
}