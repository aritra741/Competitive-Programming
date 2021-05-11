#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define mx 100007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
	fast;

	int tc;
	cin >> tc;
	int pt= tc, cc= 0;

	while (tc--)
	{
		cc++;
		int n;
		cin >> n;

		string s;
		cin >> s;

		string a = "", b = "";
		int x = 0, y = 0;
		bool f = 1;

		for ( auto c : s )
		{
			if ( c == '1' )
			{
				if ( x and y )
					x--, y--, a.push_back(')'), b.push_back(')');
				else
					x++, y++, a.push_back('('), b.push_back('(');
			}
			else
			{
				if ( x and x >= y )
					x--, y++, a.push_back(')'), b.push_back('(');
				else if ( y and y >= x )
					x++, y--, a.push_back('('), b.push_back(')');
				else
				{
					f = 0;
					break;
				}
			}
		}

		if ( x or y or !f )
		{
			cout << "NO\n";

			if( cc==64 )
				cout<<s<<endl;

			continue;
		}

		if (pt < 60)
		{
			cout << "YES\n";

			cout << a << "\n";
			cout << b << "\n";
		}

	}
}