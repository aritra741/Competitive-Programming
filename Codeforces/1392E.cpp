#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

ll arr[30][30];
int pp, n, k;

bool f;

void backtrack( int i, int j, int sum, std::vector<pii> v )
{
	if (f)
		return;
	if ( i == n and j == n )
	{
		if (sum+arr[i][j] == k)
			for ( auto x : v )
				cout << x.first << " " << x.second << endl, f = 1;
		return;
	}

	if ( i + 1 <= n and sum + arr[i][j] <= k )
	{
		v.push_back(pii(i + 1, j));
		backtrack( i + 1, j, sum + arr[i][j], v );
		v.pop_back();
	}

	if (f)
		return;

	if ( j + 1 <= n and sum + arr[i][j] <= k )
	{
		v.push_back(pii(i, j + 1));
		backtrack( i, j + 1, sum + arr[i][j], v );
		v.pop_back();
	}
}

int main()
{
	cin >> n;

	int cnt = 1;

	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			arr[i][j] = cnt;
			cnt *= 2;

			cout << arr[i][j];

			if (j < n)
				cout << " ";
		}
		cout << endl;
	}

	int q;
	cin >> q;

	while (q--)
	{
		f= 0;
		cin >> k;
		pp++;

		cout << 1 << " " << 1 << endl;
		std::vector<pii> v;
		backtrack( 1, 1, 0, v );
	}
}