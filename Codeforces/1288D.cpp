#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[300007][10];
set<int> mask;
map<int,int>idx;

bool ok()
{
	int sz = mask.size();

	for ( auto x: mask )
		for ( auto y: mask )
			if ( __builtin_popcount(x | y) == m )
				return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
			cin >> arr[i][j];

	int l = 0, r = 1000000000;
	int ans = 0;

	while (l < r - 5)
	{
		int mid = (l + r) / 2;
		mask.clear();

		for ( int i = 0; i < n; i++ )
		{
			int now = 0;

			for ( int j = 0; j < m; j++ )
				if ( arr[i][j] >= mid )
					now |= 1 << j;

			mask.insert(now);
		}

		if (ok())
			ans = mid, l = mid;
		else
			r = mid;
	}

	while (l <= r)
	{
		mask.clear();

		for ( int i = 0; i < n; i++ )
		{
			int now = 0;

			for ( int j = 0; j < m; j++ )
				if ( arr[i][j] >= l )
					now |= 1 << j;

			mask.insert(now);
		}

		if ( l > ans and ok())
			ans = l;

		l++;
	}

	mask.clear();

	for ( int i = 0; i < n; i++ )
	{
		int now = 0;

		for ( int j = 0; j < m; j++ )
			if ( arr[i][j] >= ans )
				now |= 1 << j;

		idx[now]= i+1;
		mask.insert(now);
	}

	int sz = mask.size();

	for ( auto x: mask )
		for ( auto y: mask )
			if ( __builtin_popcount(x | y) == m )
				return cout<<idx[x]<<" "<<idx[y]<<endl, 0;
}