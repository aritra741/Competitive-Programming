#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n;
	scanf("%lld", &n);

	ll arr[n+7];

	for( int i=0;i<n;i++ )
		scanf("%lld", &arr[i]);

	unordered_set<ll>ans,now;

	for( int i=0;i<n;i++ )
	{
		unordered_set<ll>tmp;

		for( auto x: now )
			tmp.insert(__gcd(x,arr[i]));

		tmp.insert(arr[i]);

		for( auto x: tmp )
			ans.insert(x);

		now.swap(tmp);
	}

	printf("%d\n", ans.size());
}