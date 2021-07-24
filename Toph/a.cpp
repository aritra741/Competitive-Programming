#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
#define yes() cout<<"Yes\n"
#define no() cout<<"No\n"
#define mod 1000000007
#define ll long long
#define mx 200007
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define ff first
#define ss second
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

std::vector<int> v[10];
ll dp[10][260][10][3];
bool vis[10][260][10][3];
bool vv[2][10];
int n, k;
string s[10];

ll rec( int i, int mask, int koyta, bool con )
{
	// cout<<i<<" "<<mask<<" "<<koyta<<" "<<con<<endl;
	if ( i >= n )
	{
		if( koyta==k and con )
			return 1;
		return 0;
	}

	if ( vis[i][mask][koyta][con] )
		return dp[i][mask][koyta][con];

	int p = v[i - 1].size();

	int m = v[i].size();

	ll ret = 0;

	for ( int kk = 0; kk < (1 << m); kk++ )
	{
		int tot = __builtin_popcount(kk);

		if ( tot + koyta > k )
			continue;

		if( !tot and koyta )
			continue;

		// cout<<i<<" "<<kk<<" entered \n";

		memset(vv, 0, sizeof(vv));
		queue<pii>q;

		for ( int j = 0; j < p; j++ )
			if ( mask & (1 << j) )
				vv[0][ v[i - 1][j] ] = 1, q.push({0, v[i - 1][j]});

		int done = 0;

		while (!q.empty())
		{
			pii u = q.front();
            q.pop();

            cout<<" "<<u.ff<<endl;

			if ( !u.ff )
			{
				if ( s[i][u.ss] == '.' and !vv[1][u.ss] and (kk & (1 << u.ss)) )
				{
					q.push({1, u.ss}), done++;
					vv[1][u.ss] = 1;
				}
			}
			else
			{
				if ( u.ss - 1 >= 0 and s[i][u.ss - 1] == '.' and !vv[1][u.ss - 1] and (kk & (1 << (u.ss - 1))) )
				{
					q.push({1, u.ss - 1}), done++;
					vv[1][u.ss - 1] = 1;
				}
				if ( u.ss + 1 < n and s[i][u.ss + 1] == '.' and !vv[1][u.ss + 1] and (kk & (1 << (u.ss + 1))) )
				{
					q.push({1, u.ss + 1}), done++;
					vv[1][u.ss + 1] = 1;
				}
			}
		}

		cout<<i<<" "<<kk<<" "<<tot<<" "<<done<<endl;

		if ( done == tot )
		{
			if (con)
			{
				ret = ( ret + rec( i + 1, kk, koyta + tot, con ) );
			}
			else
			{
				bool hoise = 1;
				int last = -1;

				for ( int j = 0; j < m; j++ )
				{
					if ( kk & (1 << j) and last>-1 and v[i][j] != last + 1 )
					{
						hoise = 0;
						break;
					}
					else if ( kk & (1 << j) )
						last = v[i][j];
				}

				if ( hoise )
					ret = ( ret + rec( i + 1, kk, koyta + tot, 1 ) );
				else
					ret = ( ret + rec( i + 1, kk, koyta + tot, con ) );
			}
		}
	}

	vis[i][mask][koyta][con] = 1;
	return dp[i][mask][koyta][con] = ret;
}

int main()
{
//	fast;

	cin >> n >> k;

	for ( int i = 0; i < n; i++ )
	{
		cin >> s[i];

		for ( int j = 0; j < n; j++ )
			if ( s[i][j] == '.' )
				v[i].push_back(j);
	}

	ll ans = 0;
	int m= v[0].size();

	for ( int mask = 0; mask < 1; mask++ )
	{
		int tot = __builtin_popcount(mask);

		if (tot > k)
			continue;

		bool hoise = 1;
		int last = -1;

		for ( int j = 0; j < m; j++ )
		{
			if ( mask & (1 << j) and last>-1 and  v[0][j] != last + 1 )
			{
				hoise = 0;
				break;
			}
			else if ( mask & (1 << j) )
				last = v[0][j];
		}

		// cout<<mask<<endl;

		ans += rec( 1, mask, tot, hoise );
	}

	cout<< ans;
}
