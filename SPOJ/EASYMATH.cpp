#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll lcm( ll a, ll b )
{
	return (a*b)/__gcd(a,b);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin>>tc;

	while(tc--)
	{
		ll n,m,a,d;
		cin>>n>>m>>a>>d;

		ll arr[7];

		for( int i=0;i<5;i++ )
			arr[i]= a+d*i;

		ll ans1= 0, ans2= 0;

		for( int mask=1;mask<(1<<5);mask++ )
		{
			ll l= 1;
			for( int i=0;i<5;i++ )
				if(mask&(1<<i))
				{
					if((m/l)<arr[i]/__gcd(l,arr[i]))
					{
						l= m+1;
						break;
					}

					l= lcm(l,arr[i]);
				}

			if( __builtin_popcount(mask)&1 )
				ans1+= m/l, ans2+= (n-1)/l;
			else 
				ans1-= m/l, ans2-= (n-1)/l;
		}

		cout<< m-n+1-(ans1-ans2) <<"\n";
	}
}