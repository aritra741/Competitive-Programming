#include <bits/stdc++.h>
#define mx 200007
using namespace std;

std::vector<int> adj[mx];
int ind1[mx], ind2[mx];

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		int n;
		string s;
		cin >> n >> s;

		for ( int i = 0; i < s.size(); i++ )
		{
			if ( s[i] == '<' )
				adj[i + 2].push_back(i + 1), ind1[i + 1]++, ind2[i + 1]++;
			else
				adj[i + 1].push_back(i + 2), ind1[i + 2]++, ind2[i + 2]++;
		}

		priority_queue<int>pq1;
		priority_queue<int, vector<int>, greater<int> >pq2;

		for ( int i = 1; i <= n; i++ )
			if ( !ind1[i] )
				pq1.push( i ), pq2.push( i );

		int ans1[n + 5], ans2[n + 5];
		int x = n;

		while (!pq1.empty())
		{
			int u = pq1.top();
			pq1.pop();

			ans1[u] = x--;

			for ( auto y : adj[u] )
			{
				ind1[y]--;

				if (!ind1[y])
					pq1.push(y);
			}
		}

		x = n;

		while (!pq2.empty())
		{
			int u = pq2.top();
			pq2.pop();

			ans2[u] = x--;

			for ( auto y : adj[u] )
			{
				ind2[y]--;

				if (!ind2[y])
					pq2.push(y);
			}
		}

		for ( int i = 1; i <= n; i++ )
			cout << ans2[i] << " ";
		cout << "\n";

		for ( int i = 1; i <= n; i++ )
			cout << ans1[i] << " ";
		cout << "\n";

		for ( int i = 1; i <= n; i++ )
			ind1[i] = 0, ind2[i] = 0, adj[i].clear();
	}
}