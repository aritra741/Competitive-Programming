#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
using namespace std;

int main()
{
	ll n;
	cin >> n;

	ll arr[n + 5][n + 5];
	ll b_max[n + 5], b_min[n + 5];

	for ( ll i = 0; i < n; i++ )
		for ( ll j = 0; j < n; j++ )
			cin >> arr[i][j];


	ll b_final[n + 5];

	for ( ll mask = 0; mask < (1 << n); mask++ )
	{
		ll sumtot = 0, minsumtot = 0;

		ll b[n+5];

		for( ll i=0;i<n;i++ )
			if( mask&(1<<i) )
				b[i]= 1;
			else
				b[i]= -1;

		for ( ll i = 0; i < n; i++ )
		{
			ll sum = 0;

			for ( ll j = 0; j < n; j++ )
			{
				sum += arr[i][j] * b[j];
			}			

			sumtot += sum * sum;
			// minsumtot += minsum * minsum;
		}
		
		cout<<sumtot<<endl;

	}

	// for ( ll i = 0; i < n; i++ )
	// {
	// 	if (maxsumtot >= minsumtot)
	// 		b_final[i] = b_max[i];
	// 	else
	// 		b_final[i] = b_min[i];
	// }

	// cout << maxsumtot << " " << minsumtot << endl;

}