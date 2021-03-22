#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll val( ll n )
{
	return ((n*(n+1))/2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		int n;
		cin>>n;

		ll ans= 0;

		for( int i=1;i*i<=n;i++ )
		{
			int y= i;
			int x= n/y;

			int l= 1, r= x, now= r;
			now= n/(y+1);
			now++;

			ll tot= (( val(x)-val(now-1) )%mod+mod)%mod;
			tot= (tot*y)%mod;

			ans= ( ans+tot )%mod; 

			if(i==n/i)
				continue;

			y= n/i;
			x= i;

			l= 1, r= x, now= r;
			now= n/(y+1);
			now++;

			tot= (( val(x)-val(now-1) )%mod+mod)%mod;
			tot= (tot*y)%mod;

			ans= ( ans+tot )%mod; 			
		}

		cout<< ans <<"\n";
	}
}