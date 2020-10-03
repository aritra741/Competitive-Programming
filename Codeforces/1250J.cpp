#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int tc;
	cin>>tc;

	while(tc--)
	{
		ll n,k;
		cin>>n>>k;

		ll arr[n+5];

		for( int i=0;i<n;i++ )
			cin>>arr[i];

		ll l= 1, r= 1e15, ans= 0;

		while(l<=r)
		{
			ll x= (l+r)/2;

			ll residue= 0;
			ll cnt= 0;

			for( int i=0;i<n;i++ )
			{
				if( arr[i]+residue>=x )
					cnt+= (arr[i]+residue)/x, residue= min( arr[i], (arr[i]+residue)%x );
				else
					residue= arr[i];
			}

			if(cnt>=k)
				ans= x, l= x+1;
			else
				r= x-1;
		} 

		cout<<ans*k<<"\n";
	}	
}