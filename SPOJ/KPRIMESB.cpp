#include <bits/stdc++.h>
#define ll long long
#define mx 1000007
using namespace std;

std::vector<int> v;
bool ok[mx];

void sieve()
{
	ok[0]= ok[1]= 1;
	v.push_back(2);

	for( ll i=3;i<mx;i+=2 )
	{
		if(!ok[i])
		{
			v.push_back(i);

			for( ll j=i*i;j<mx;j+=i*2 )
				ok[j]= 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	sieve();

	int tc;
	cin>>tc;

	for( int t=1;t<=tc;t++ )
	{
		int n,k;
		cin>>n>>k;

		int pos= upper_bound(v.begin(), v.end(),n)-v.begin();

		int arr[k+5];

		for( int i=0;i<k;i++ )
			cin>>arr[i];

		ll ans= 0;

		for( int mask=1;mask<(1<<k);mask++ )
		{
			ll l= 1;

			for( int j=0;j<k;j++ )
				if(mask&(1<<j))
					l*= arr[j];

			if(__builtin_popcount(mask)&1)
				ans+= n/l;
			else
				ans-= n/l; 
		}

		ans= n-ans-pos;

		for( int i=0;i<k;i++ )
			if(arr[i]<=n)
				ans++;

		if(n>=1)
			ans--;

		cout<<"Case "<<t<<": "<<ans<<"\n";
	}	
}