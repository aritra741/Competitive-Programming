#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;

	bool rootred = 0;

	while(q--)
	{
		string s;
		int u, v;

		cin >> s ;

		if (s[1] == 'i')
			rootred ^= 1;
		else if (s[1] == 'b')
		{
			cin>>u>>v;
			map<int, int>mp;

			int x = u;
			mp[x]++;

			while (x > 1)
				x /= 2, mp[x]++;

			x = v;
			int lca = 1;

			while (x >= 1)
			{
				if ( mp[x] )
				{
					lca = x;
					break;
				}

				x /= 2;
			}

			x = u;
			int ans = 0;

			while (x > lca)
			{
				int lvl = log2(x) + 1e-9;

				if ( !rootred and lvl % 2 == 0 )
					ans++;
				else if ( rootred and lvl % 2 == 1 )
					ans++;

				x /= 2;
			}

			x = v;

			while (x > lca)
			{
				int lvl = log2(x) + 1e-9;

				if ( !rootred and lvl % 2 == 0 )
					ans++;
				else if ( rootred and lvl % 2 == 1 )
					ans++;

				x /= 2;
			}

			int lvl = log2(lca) + 1e-9;

			if ( !rootred and lvl % 2 == 0 )
				ans++;
			else if ( rootred and lvl % 2 == 1 )
				ans++;


			cout<< ans <<"\n";
		}
		else
		{
			cin>>u>>v;
			map<int, int>mp;

			int x = u;
			mp[x]++;

			while (x > 1)
				x /= 2, mp[x]++;

			x = v;
			int lca = 1;

			while (x >= 1)
			{
				if ( mp[x] )
				{
					lca = x;
					break;
				}

				x /= 2;
			}

			x = u;
			int ans = 0;

			while (x > lca)
			{
				int lvl = log2(x) + 1e-9;

				if ( rootred and lvl % 2 == 0 )
					ans++;
				else if ( !rootred and lvl % 2 == 1 )
					ans++;

				x /= 2;
			}

			x = v;

			while (x > lca)
			{
				int lvl = log2(x) + 1e-9;

				if ( rootred and lvl % 2 == 0 )
					ans++;
				else if ( !rootred and lvl % 2 == 1 )
					ans++;

				x /= 2;
			}

			int lvl = log2(lca) + 1e-9;

			if ( rootred and lvl % 2 == 0 )
				ans++;
			else if ( !rootred and lvl % 2 == 1 )
				ans++;

			cout<<ans<<"\n";
		}
	}
}