#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	map<int, int>mp;
	int two = 0, four = 0, six = 0, eight = 0;

	int arr[n + 5];

	for ( int i = 0; i < n; i++ )
	{
		cin >> arr[i];

		int x = arr[i];
		mp[x]++;

		if ( mp[x] == 2 )
			two++;
		else if ( mp[x] == 4 )
			four++, two--;
		else if ( mp[x] == 6 )
			six++, four--;
		else if ( mp[x] == 8 )
			eight++, six--;
	}

	int q;
	cin >> q;

	while (q--)
	{
		char c;
		int x;
		cin >> c >> x;

		if (c == '+')
		{
			mp[x]++;

			if ( mp[x] == 2 )
				two++;
			else if ( mp[x] == 4 )
				four++, two--;
			else if ( mp[x] == 6 )
				six++, four--;
			else if ( mp[x] == 8 )
				eight++, six--;
		}
		else
		{
			mp[x]--;

			if ( mp[x] == 1 )
				two--;
			else if ( mp[x] == 3 )
				four--, two++;
			else if ( mp[x] == 5 )
				six--, four++;
			else if ( mp[x] == 7 )
				eight--, six++;
		}

		if ( (two and six) or (eight) or (four > 1 or six > 1 or eight > 1) or (four and two > 1) or (two > 1 and six) or (two > 1 and eight) or (four and six) or (four and eight) or (six and eight) )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}