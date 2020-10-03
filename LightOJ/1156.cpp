#include <bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);

	for ( int t = 1; t <= tc; t++ )
	{
		int n, d;
		scanf("%d %d", &n , &d);

		set<int> boro, chhoto;

		for ( int i = 1; i <= n; i++ )
		{
			char c;
			int m;

			scanf(" %c-%d", &c, &m);

			if (c == 'B')
				boro.insert(m);
			else
				chhoto.insert(m);
		}

		// cout<<"sz "<<boro.size()<<" "<<chhoto.size()<<endl;

		int l = 1, r = d, ans = d;

		while (r - l > 5)
		{
			int mid = (r + l) / 2;
			int x = 0;
			bool f = 0;

			set<int>bor, chh;
			bor = boro, chh = chhoto;

			// cout<<mid<<": ";

			while (x <= d)
			{
				// cout << x << " ";
				if (d - x <= mid)
				{
					f = 1;
					break;
				}

				auto bb = bor.upper_bound( x );
				// cout<<" sage"<<*bb<<endl;
				if ( bb != bor.end() and * (bb) - x <= mid )
				{
					x = *(bb);
					continue;
				}
				// cout<<"ashe "<<x<<" "<<*bb<<endl;
				int z = -1;
				for ( auto it = chh.rbegin(); it != chh.rend(); it++ )
				{
					int y = *it;

					if ( y > x and y - x <= mid )
					{
						z = y;
						break;
					}
				}

				if (z > -1)
				{
					x = z;
					chh.erase(z);
					continue;
				}

				break;
			}

			bool f2 = 0;

			if (f)
			{
				x = d;

				while (x >= 0)
				{
					// cout << x << " ";
					if ( x <= mid )
					{
						f2 = 1;
						break;
					}
					int z = -1;
					for ( auto it = bor.rbegin(); it != bor.rend(); it++ )
					{
						int y = *it;
						if ( y < x )
						{
							if (x - y > mid)
								break;
							z = y;
							break;
						}
					}

					if (z > -1)
					{
						x = z;
						continue;
					}

					for ( auto y : chh )
					{
						if ( y < x and x - y <= mid )
						{
							z = y;
							break;
						}
					}

					if (z > -1)
					{
						x = z;
						continue;
					}

					break;
				}
			}

			// cout << "\n";

			if (f and f2)
				ans = mid, r = mid;
			else
				l = mid;
		}

		// cout<<l<<" "<<r<<endl;

		while (l <= r)
		{
			int x = 0;
			bool f = 0;

			set<int>bor, chh;
			bor = boro, chh = chhoto;

			// cout<<l<<": ";

			while (x <= d)
			{
				// cout << x << " ";
				if (d - x <= l)
				{
					f = 1;
					break;
				}

				auto bb = bor.upper_bound( x );
				// cout<<" sage"<<*bb<<endl;
				if ( bb != bor.end() and * (bb) - x <= l )
				{
					x = *(bb);
					continue;
				}
				// cout<<"ashe "<<x<<" "<<*bb<<endl;
				int z = -1;
				for ( auto it = chh.rbegin(); it != chh.rend(); it++ )
				{
					int y = *it;

					if ( y > x and y - x <= l )
					{
						z = y;
						break;
					}
				}

				if (z > -1)
				{
					x = z;
					chh.erase(z);
					continue;
				}

				break;
			}

			bool f2 = 0;

			if (f)
			{
				x = d;

				while (x >= 0)
				{
					// cout << x << " ";
					if ( x <= l )
					{
						f2 = 1;
						break;
					}
					int z = -1;
					for ( auto it = bor.rbegin(); it != bor.rend(); it++ )
					{
						int y = *it;
						if ( y < x )
						{
							if (x - y > l)
								break;
							z = y;
							break;
						}
					}

					if (z > -1)
					{
						x = z;
						continue;
					}

					for ( auto y : chh )
					{
						if ( y < x and x - y <= l )
						{
							z = y;
							break;
						}
					}

					if (z > -1)
					{
						x = z;
						continue;
					}

					break;
				}
			}
			if (f and f2 and l < ans )
				ans = l;

			l++;
		}

		printf("Case %d: %d\n", t, ans );
	}
}