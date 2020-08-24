#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		int r, g, b, w;
		cin >> r >> g >> b >> w;

		int e = 0, o = 0;

		if (r & 1)
			o++;
		else
			e++;
		if (g & 1)
			o++;
		else
			e++;
		if (b & 1)
			o++;
		else
			e++;
		if (w & 1)
			o++;
		else
			e++;

		if (e == 2)
			cout << "No\n";
		else if (e != 1)
			cout << "Yes\n";
		else
		{
			if ( r and g and b )
				cout << "Yes\n";
			else
				cout << "No\n";
		}
	}
}