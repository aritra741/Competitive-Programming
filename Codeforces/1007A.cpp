#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
	fast;

	int n;
	cin>>n;

	int arr[n+5];
	multiset<int>st;

	for( int i=1;i<=n;i++ )
		cin>>arr[i], st.insert(arr[i]);

	sort( arr+1, arr+n+1 );

	int ans= 0;

	for( int i=1;i<=n;i++ )
	{
		if(st.empty())
			break;

		auto x= (st.upper_bound( arr[i] ));

		if(x==st.end())
			continue;

		st.erase(st.find(*x));
		ans++;
	}

	cout<< ans;
}