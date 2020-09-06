#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll Pow( ll x, ll y )
{
	ll res= 1;

	while(y>0)
	{
		if(y&1)
			res*= x;
		x*= x;
		y>>= 1;
	}

	return res;
}

int main()
{
	int tc;
	scanf("%d", &tc);

	for(int t=1;t<=tc;t++)
	{
		ll n;
		scanf("%lld", &n);

		ll ans= 1, mx= sqrt(abs(n))+1;

		for( ll i=2;i<=32;i++ )
		{
			if( n<0 and i%2==0 )
				continue;

			ll l= 1, r= mx;
			ll now= -1;
			bool f= 0;

			// cout<<i<<" "<<l<<" "<<r<<endl;

			while( l<r-5 )
			{
				ll mid= (l+r)/2;
				ll x= Pow(mid,i);

				if( x==abs(n) )
				{
					mx= mid;
					f= 1;
					now= i;
					break;
				}

				if(x<abs(n))
					l= mid;
				else
					r= mid, mx= mid;
			}

			// cout<<" "<<l<<" "<<r<<endl;

			while(l<=r)
			{
				if( Pow(l,i)==abs(n) )
				{
					now= i;
					mx= l;
					break;
				}

				l++;
			}

			// cout<<i<<" "<<mx<<endl;
			ans= max( ans, now );

		}

		printf("Case %d: %d\n", t, ans);
	}
}