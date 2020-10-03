#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

multiset<int>pt;
multiset<int, greater<int> >sz;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	int arr[n + 7];

	for ( int i = 0; i < n; i++ )
		cin >> arr[i];

	sort( arr, arr + n );

	pt.insert(arr[0]);
	for ( int i = 1; i < n; i++ )
	{
		pt.insert(arr[i]);
		sz.insert( arr[i] - arr[i - 1] );
	}

	int ans = arr[n - 1] - arr[0];

	if ( sz.size() )
		ans -= *sz.begin();

	cout << ans << "\n";

	while (q--)
	{
		int tp, x;
		cin >> tp >> x;

		if ( tp )
		{
			pt.insert(x);

			auto it = pt.find(x);

			if ( it != pt.begin() and next(it) != pt.end() )
				sz.erase( sz.find( (*next(it)) - (*prev(it)) ) );

			if ( it != pt.begin() )
				sz.insert( x - (*(prev(it))) );

			if ( next(it) != pt.end() )
				sz.insert( (*(next(it))) - x );
		}
		else
		{
			auto it = pt.find( x );

			if ( it != pt.begin() and next(it) != pt.end() )
				sz.insert( (*next(it)) - (*prev(it)) );

			if ( it != pt.begin() )
				sz.erase( sz.find(x - (*(prev(it)))) );

			if ( next(it) != pt.end() )
				sz.erase( sz.find((*(next(it))) - x));

			pt.erase(x);
		}

		if ( pt.size() > 2 )
		{
			auto it = pt.begin();
			auto it2 = pt.end();
			it2--;
			cout << (*it2) - (*it) - (*(sz.begin())) << "\n";
		}
		else
			cout<<"0\n";
	}
}