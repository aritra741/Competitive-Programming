#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 100007
using namespace std;

std::vector<pii> bl[350];
int ans[mx], last[mx];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[n + 7];
	int sq = 300;
	int tot = 0;

	for ( int i = 0; i < n; i++ )
	{
		cin >> arr[i];
		int block = i / sq;
		tot = max(tot, block);
		bl[block].push_back({arr[i], i});
	}

	for ( int i = tot; i >= 0; i-- )
	{
		if (bl[i].empty())
			continue;
		for ( int j = bl[i].size() - 1; j >= 0; j-- )
		{
			pii p = bl[i][j];
			int nxtBlock = (p.ss + p.ff) / sq;

			if (nxtBlock > i or p.ss + p.ff>=n )
				ans[p.ss] = 1, last[p.ss] = p.ss;
			else
				ans[p.ss] = ans[p.ff + p.ss] + 1, last[p.ss] = last[p.ff + p.ss];
		}
	}

	while (m--)
	{
		int tp;
		cin >> tp;

		if (tp)
		{
			int a;
			cin >> a;

			a--;

			int block = a / sq;
			int jumps = 0;
			int x = a;
			int y = x;

			while (x < n)
			{
				jumps += ans[x];
				y = last[x];
				x = last[x] + arr[last[x]];
			}

			cout << y + 1 << " " << jumps << "\n";
		}
		else
		{
			int a, b;
			cin >> a >> b;

			a--;

			arr[a]= b;

			int block= a/sq;

			for ( int j = bl[block].size() - 1; j >= 0; j-- )
			{
				pii p = bl[block][j];
				
				if(p.ss==a)
					p.ff= b;

				bl[block][j]= p;

				int nxtBlock = (p.ss + p.ff) / sq;

				if (nxtBlock > block or p.ss + p.ff>=n )
					ans[p.ss] = 1, last[p.ss] = p.ss;
				else
					ans[p.ss] = ans[p.ff + p.ss] + 1, last[p.ss] = last[p.ff + p.ss];
			}
		}
	}
}