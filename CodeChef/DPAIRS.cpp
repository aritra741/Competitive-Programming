#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	pii a[n + 5], b[m + 5];

	for ( int i = 0; i < n; i++ )
		cin >> a[i].ff, a[i].ss = i;
	for ( int i = 0; i < m; i++ )
		cin >> b[i].ff, b[i].ss = i;

	sort( a, a + n );
	sort( b, b + m );

	int cnt = 0;

	for ( int j = m - 1; j >= 0; j-- )
	{
		cout << a[n - 1].ss << " " << b[j].ss << "\n";
	}

	for ( int i = 0; i < n - 1; i++ )
		cout << a[i].ss << " " << b[0].ss << "\n";
}