#include <bits/stdc++.h>
using namespace std;

int ans[100007];

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		string s;
		cin >> s;

		int x;
		cin >> x;

		for ( int i = 0; i < s.size(); i++ )
			ans[i] = -1;

		bool f = 0;

		for ( int i = 0; i < s.size(); i++ )
		{
			if ( s[i] == '0' )
			{
				if ( i - x >= 0 )
					ans[i - x] = 0;

				if ( i + x < s.size() )
					ans[i + x] = 0;
			}
		}

		for ( int i = 0; i < s.size(); i++ )
		{
			if( s[i]=='0' )
				continue;
			if ( i + x < s.size() and i - x >= 0 )
			{
				if ( !ans[i - x] and !ans[i + x] )
				{
					f = 1;
					break;
				}
			}
			else if ( i - x >= 0 and !ans[i - x] )
			{
				f = 1;
				break;
			}
			else if ( i + x < s.size() and !ans[i + x] )
			{
				f = 1;
				break;
			}
			if( i+x>=s.size() and i-x<0 )
			{
				f= 1;
				break;
			}
		}

		if ( f )
			cout << "-1";
		else
			for ( int i = 0; i < s.size(); i++ )
				cout << ((ans[i]) ? 1 : 0);

		cout << "\n";
	}
}