#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007
#define mx 100007
#define pii pair<int,int>
#define pci pair<int,int>
#define ff first
#define ss second
#define piii pair<int,pii>
using namespace std;

map<int,int>mp;

bool cmp( int a, int b )
{
	return mp[a] > mp[b];
}


int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		mp.clear();

		int n;
		cin >> n;

		int arr[n + 5];
		vector<int>occ;

		for ( int i = 0; i < n; i++ )
			cin >> arr[i], mp[arr[i]]++;

		cout<< ans <<"\n";
	}
}
