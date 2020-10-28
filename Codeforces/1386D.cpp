#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[200007];
int mp[25];

ll ans[200007];

int main()
{
	int n;
	cin>>n;

	for( int i=1;i<=n;i++ )
	{
		cin>>arr[i];

		for( int j=0;j<=21;j++ )
			if( arr[i]&(1LL<<j) )
				mp[j]++;
	}

	for( int i=0;i<=20;i++ )
	{
		if(!mp[i])
			continue;
		
		ans[1]+= 1LL<<i;
		ans[ mp[i]+1 ]-= 1LL<<i;
	}

	ll tot= 0;

	for( int i=1;i<=n;i++ )
		ans[i]+= ans[i-1], tot+= ans[i]*ans[i];

	cout<< tot <<"\n";
}