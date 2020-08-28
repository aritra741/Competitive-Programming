#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second
#define inf 1000000000000000LL
using namespace std;

ll dp[150007][2];
ll a[150007], b[150007], t[150007];

deque<pii>dq;

void operation1( int baad, int i, int j )
{
	while ( dq.size() and dq.front().ff < baad ) dq.pop_front();
	while ( dq.size() and dq.back().ss < dp[i][j] ) dq.pop_back();

	dq.push_back({i, dp[i][j]});
}

void operation2( int baad, int i, int j )
{
	while ( dq.size() and dq.front().ff > baad ) dq.pop_front();
	while ( dq.size() and dq.back().ss < dp[i][j] ) dq.pop_back();

	dq.push_back({i, dp[i][j]});
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n, m, d;
	cin >> n >> m >> d;

	for ( int i = 1; i <= m; i++ )
		cin >> a[i] >> b[i] >> t[i];

	int now = 0;
	for ( int i = 1; i <= m; i++ )
	{
		ll k = min( n, (t[i] - t[i - 1]) * d );

		dq.clear();

		for ( int j = 1; j <= n; j++ )
		{
			operation1( j - k, j, now ^ 1 );

			dp[j][now] = dq.front().ss;
			dp[j][now] += b[i] - abs(a[i] - j);
		}

		dq.clear();

		for ( int j = n; j >= 1; j-- )
		{
			operation2( j + k, j, now ^ 1 );
			dp[j][now] = max( dp[j][now], dq.front().ss + b[i] - abs(a[i] - j) );
		}

		now ^= 1;
	}

	ll ans = -inf;

	for ( int i = 1; i <= n; i++ )
		ans = max( ans, dp[i][now ^ 1] );

	cout << ans << "\n";
}