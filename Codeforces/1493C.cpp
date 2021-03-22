#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		int cnt[26] = {};
		bool f= 0;

		if(n%k)
		{
			cout<<"-1\n";
			continue;
		}

		for ( auto c : s )
			cnt[c - 'a']++;

		bool yes= 1;

		for( auto c: s )
			if( cnt[c-'a']%k )
				yes= 0;

		if(yes)
		{
			cout<<s<<"\n";
			continue;
		}

		for ( int i = n - 1; i >= 0 and !f; i-- )
		{
			int x = s[i] - 'a';
			cnt[x]--;

			for ( int j = x + 1; j < 26 and !f; j++ )
			{
				cnt[j]++;
				int lagbe = 0;

				for ( int p = 0; p < 26; p++ )
					lagbe += (k - cnt[p] % k) % k;

				// cout<<i<<" "<<j<<" "<<lagbe<<endl;
				if(lagbe<=n-i-1)
				{
					int pos= n-1;

					for( int p=25;p>=0;p-- )
					   while(cnt[p]%k)
							s[pos--]= p+'a', cnt[p]++;

					while(pos>i)
						s[pos--]= 'a';

					s[i]= j+'a';
					f= 1;
				}

				cnt[j]--;
			}
		}

		if(f)
			cout<<s<<"\n";
		else
			cout<<"-1\n";
	}
}