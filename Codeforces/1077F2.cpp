#include <bits/stdc++.h>
#define inf 1000000000000000LL
#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second
using namespace std;

ll arr[5007];
ll dp[5007][5007];
deque<pii>dq;

void notun( int baad, int i, int j )
{
	while( dq.size() and dq.front().first<baad ) dq.pop_front();
	while( dq.size() and dq.back().second<=dp[i][j] ) dq.pop_back();

	dq.push_back({i, dp[i][j]});
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k,x;
	cin>>n>>k>>x;

	if( x>n or k>n or (n+2*k-2)/(2*k-1)>x )
		return cout<<"-1\n", 0;

	for( int i=1;i<=n;i++ )
		cin>>arr[i];

	for( int i=0;i<=n;i++ )
		for( int j=0;j<=x;j++ )
			dp[i][j]= -inf;

	dp[0][0]= 0;

	for( int j=1;j<=x;j++ )
	{
		dq.clear();

		for( int i=1;i<=n;i++ )
		{
			notun( i-k, i-1, j-1 );
			ll boro= dq.front().second;

			dp[i][j]= boro+arr[i];
		}
	}

	ll ans= -inf;

	for( int i=max(1,n-k+1);i<=n;i++ )
		ans= max( ans, dp[i][x] );

	if(ans<0)
		ans= -1;

	cout<< ans <<"\n";

	if
}