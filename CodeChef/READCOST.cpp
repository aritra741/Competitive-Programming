#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll n,m,x;

	while( cin>>n>>m>>x and (n+m+x) )
	{
		ll ff= x/m;
		ll left= -1;

		ll last= (x+(m-1)*n)/m;
		ll pp= -1;

		ll tot= 0;
		// cout<<ff<<" "<<last<<endl;
		for( int i=ff;i<=last and left+1<=m-1;i++ )
		{
			// cout<<i<<endl;
			ll l= left+1;
			ll r= m-1;
			ll ans= left+1;

			ff= (x+l*n)/m;

			while(l<=r)
			{
				ll mid= (l+r)/2;
				// cout<<l<<" "<<r<<endl;
				if( (x+mid*n)/m>ff )
					r= mid-1;
				else
					ans= mid, l= mid+1;
			}

			tot+= (ans-(left+1)+1)*ff;
			left= ans;
		}

		cout<< tot <<"\n";
	}
}