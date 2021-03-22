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
		int n, u, r, d, l;
		cin >> n >> u >> r >> d >> l;

		int arr[4];
		arr[0] = max(0, u - 2);
		arr[1] = max(0, r - 2);
		arr[2] = max(0, d - 2);
		arr[3] = max(0, l - 2);

		bool f = 0;

		for ( int i = 0; i < (1 << 4); i++ )
		{
			int brr[4];
			int cnt = 0;

			for ( int j = 0; j < 4; j++ )
			{
				brr[j] = arr[j];

				if (i & (1 << j))
					brr[j]++;

				if (i & (1 << ((j + 1) % 4)))
					brr[j]++;

				if ( j == 0 and brr[j] == u )
					cnt++;
				if ( j == 1 and brr[j] == r )
					cnt++;
				if ( j == 2 and brr[j] == d )
					cnt++;
				if ( j == 3 and brr[j] == l )
					cnt++;
			}

			if (cnt == 4)
				f = 1;
		}

		if (!f)
		{
			arr[0] = max( n-2, u-1 );
			arr[1] = max( n-2, r-1 );
			arr[2] = max( n-2, d-1 );
			arr[3] = max( n-2, l-1 );
			
			cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<endl;

			for ( int i = 0; i < (1 << 4); i++ )
			{
				int brr[4];
				int cnt = 0;

				for ( int j = 0; j < 4; j++ )
				{
					brr[j] = arr[j];

					if (i & (1 << j))
						brr[j]++;

					if (i & (1 << ((j + 1) % 4)))
						brr[j]++;

					if ( j == 0 and brr[j] == u )
						cnt++;
					if ( j == 1 and brr[j] == r )
						cnt++;
					if ( j == 2 and brr[j] == d )
						cnt++;
					if ( j == 3 and brr[j] == l )
						cnt++;
				}

				if (cnt == 4)
					f = 1;
			}
		}

		if (!f)
		{
			if (n - 1 > u)
				arr[0] = u;
			else
				arr[0] = max(0, n - 2);
			if (n - 1 > r)
				arr[1] = r;
			else
				arr[1] = max(0, n - 2);
			if (n - 1 > d)
				arr[2] = d;
			else
				arr[2] = max(0, n - 2);
			if (n - 1 > l)
				arr[3] = l;
			else
				arr[3] = max(0, n - 2);


			for ( int i = 0; i < (1 << 4); i++ )
			{
				int brr[4];
				int cnt = 0;

				for ( int j = 0; j < 4; j++ )
				{
					brr[j] = arr[j];

					if (i & (1 << j))
						brr[j]++;

					if (i & (1 << ((j + 1) % 4)))
						brr[j]++;

					if ( j == 0 and brr[j] == u )
						cnt++;
					if ( j == 1 and brr[j] == r )
						cnt++;
					if ( j == 2 and brr[j] == d )
						cnt++;
					if ( j == 3 and brr[j] == l )
						cnt++;
				}

				if (cnt == 4)
					f = 1;
			}
		}

		if (f)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}