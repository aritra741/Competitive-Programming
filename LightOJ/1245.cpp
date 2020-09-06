#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);

	for( int t=1;t<=tc;t++ )
	{
		int n;
		scanf("%d", &n);

		ll ans1= 0, ans= 0, sq= sqrt(n);

		std::vector<int> v;

		for( int i=1;i<=sq;i++ )
		{
			v.push_back(i);
			v.push_back(n/i);

			int x= i;
			int y= n/i;

			if(x>y)
				break;

			ans+= x*(n/x-n/(x+1));

			if(x!=y)
				ans+= y*(n/y-n/(y+1));
		}

		printf("Case %d: %lld\n", t, ans);
	}
}