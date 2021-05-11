#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define mx 1000007
using namespace std;

ll stbr3( ll n )
{
	if(n<0)
		return 0;
	return ((n-1)*(n-2))/2;
}

ll stbr2( ll n )
{
	if(n<0)
		return 0;
	return n-1;
}

int main()
{
	fast;

	ll n,k;
	cin>>n>>k;

	ll baki= k, gese= 0;

	for( ll i=1;i<=n;i++ )
	{
		ll now= 1+n*n;
		cout<<i<<" "<<baki<<" "<<now+gese<<endl;
		if( baki-now-gese>0 )
		{
			gese+= now;
			continue;
		}

		for( int j=1;j<=n;j++ )
		{
			ll pore= now-i-j;
			// cout<<i<<" "<<j<<" "<<pore<<" "<<baki<<endl;
			if( 1LL*(i-1)*n*n+1LL*(j-1)*n+pore+gese+1==baki )
			{
				cout<<i<<" "<<j<<" "<<pore;
				return 0;
			}
		}

		gese+= now;
	}
}