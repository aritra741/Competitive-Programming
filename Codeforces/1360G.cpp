#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		int n, m, a, b;
		cin >> n >> m >> a >> b;

		if ( n * a != m * b )
		{
			cout << "NO\n";
			continue;
		}

		std::vector<pii> v;

		for ( int j = 0; j < m; j++ )
			v.push_back(pii(0, j));

		cout << "YES\n";

		int ans[n + 5][m + 5];
		memset(ans, 0, sizeof(ans));
		int cntrow[n + 5];
		memset(cntrow, 0, sizeof(cntrow));

		for ( int i = 0; i < n; i++ )
		{
			for ( int j = 0; j < m; j++ )
			{
				if(cntrow[i]==a)
					break;
				if ( !ans[i][v[j].second] and v[j].first < b )
				{
					ans[i][v[j].second] = 1;
					cntrow[i]++;
					v[j].first++;
				}
			}

			sort( v.begin(), v.end() );
		}

		for ( int i = 0; i < n; i++ )
		{
			int cc = 0;
			for ( int j = 0; j < m; j++ )
				cout << ans[i][j], cc += (ans[i][j]);
			cout << endl;
		}
	}
}