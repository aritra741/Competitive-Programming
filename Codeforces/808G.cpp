#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s,ss;

	cin >> ss;
	cin >> s;

	n = ss.size();
	m = s.size();
	s += "#";
	m++;

	int lps[m + 7], automaton[m + 7][30];

	lps[0] = 0;
	for (int i = 1; i < m; i++)
	{
		int j = lps[i - 1];
		while (j > 0 && s[i] != s[j])j = lps[j - 1];
		if (s[i] == s[j])j++;
		lps[i] = j;
	}

	for ( int i = 0; i < m; i++ )
		for ( char c = 'a'; c <= 'z'; c++ )
		{
			if ( i and s[i] != c )
				automaton[i][c - 'a'] = automaton[lps[i - 1]][c - 'a'];
			else
				automaton[i][c - 'a'] = i + (s[i] == c);
		}

	m--;

	int dp[n + 7][m + 7];

	for ( int i = n; i >= 0; i-- )
		for ( int mat = m; mat >= 0; mat-- )
		{
			dp[i][mat] = 0;
			if ( i == n )
			{
				dp[i][mat] = (mat == m);
			}
			else
			{
				if ( ss[i] == '?' )
				{
					for ( char c = 'a'; c <= 'z'; c++ )
						dp[i][mat] = max(dp[i][mat], dp[i + 1][automaton[mat][c - 'a']]);
				}
				else
				{
					dp[i][mat] = dp[i + 1][automaton[mat][ss[i] - 'a']];
				}

				dp[i][mat] += (mat == m);
			}
		}

	cout << dp[0][0];
}
