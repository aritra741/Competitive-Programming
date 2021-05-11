#include <bits/stdc++.h>
#define ll long long
#define lim 100007
using namespace std;

ll dp[lim][107];
bool vis[lim][107];
int arr[107];

ll rec( ll n, int k )
{
	if( n==0 )
		return 0;
	if(k==0)
		return n;

	if(n<=lim)
	{
		if(vis[n][k])
			return dp[n][k];
	}

	ll ret= rec( n, k-1 )-rec( n/arr[k], k-1 );

	if(n<=lim)
		vis[n][k]= 1, dp[n][k]= ret;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n,k;
	cin>>n>>k;

	for( int i=1;i<=k;i++ )
		cin>>arr[i];

	sort( arr+1, arr+k+1, greater<int>() );

	cout<< rec( n, k );
}