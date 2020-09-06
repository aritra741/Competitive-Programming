#include <bits/stdc++.h>
#define ll long long
#define mx 1000507
using namespace std;

bool ok[mx];
std::vector<int> pr;

void sieve()
{
    for (ll i = 2; i < mx; ++i)
    {
        if(ok[i])
        	continue;

        pr.push_back(i);
        for( ll j=i*2;j<mx;j+=i )
        	ok[j]= 1;
    }
}

int main()
{
	sieve();

	int tc;
	scanf("%d", &tc);

	for( int t=1;t<=tc;t++ )
	{
		int n;
		scanf("%d", &n);

		ll ans= 0;

		for( int i=0;i<n;i++ )
		{
			int x;
			scanf("%d", &x);

			int pos= upper_bound( pr.begin(), pr.end(), x )-pr.begin();
			ans+= pr[pos];
		}

		printf("Case %d: %lld Xukha\n", t, ans);
	}
}